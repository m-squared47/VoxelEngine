#version 330 core
out vec4 FragColor;

in vec3 color;
in vec2 texCoord;
in vec3 Normal;
in vec3 currPos;

uniform sampler2D tex0;

uniform vec4 lightColor;
uniform vec3 lightPos;
uniform vec3 camPos;

void main()
{
	// ambient light
	float ambient = 0.20f;

	// diffuse light
	vec3 normal = normalize(Normal);
	vec3 lightDirection = normalize(lightPos - currPos);
	float diffuse = max(dot(normal, lightDirection), 0.0f);

	// specular light
	float specularLight = 0.50f;
	vec3 viewDirection = normalize(camPos - currPos);
	vec3 reflectDirection = reflect(-lightDirection, normal);
	float specAmount = pow(max(dot(viewDirection, reflectDirection), 0.0f), 8);
	float specular = specAmount * specularLight;

	FragColor = texture(tex0, texCoord) * lightColor * (diffuse + ambient + specular);
}