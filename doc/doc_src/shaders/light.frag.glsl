# version 330 core
// modern OpenGL is used, your OpenGL version should
// be at least 3.1 (corresponding to GLSL version 140, which somehow has forward
// compatibility to the above listed version 330). Do NOT change the version
// directive to "version 140" or "version 150," as the shader will fail (due to modern
// OpenGL not yet being core at that point in time).

// Inputs to the fragment shader are the outputs (of the same name) of the vertex shader.
in vec3 Normal;
in vec4 Position;

// The output of the fragment shader will determine the fragment's color
out vec4 fragColor;

uniform int islight ; // are we lighting.

uniform vec3 color; // RGB color normally used in glColor*

// Assume light 0 and light 1 are both point lights
// The actual light values are passed from the main OpenGL program.

uniform vec4 light0posn ; 
uniform vec4 light0color ; 
uniform vec4 light1posn ; 
uniform vec4 light1color ; 

// Now, set the material parameters.
// I use ambient, diffuse, specular, shininess.
// But, the ambient is just additive and doesn't multiply the lights.

uniform vec4 ambient ; 
uniform vec4 diffuse ; 
uniform vec4 specular ; 
uniform float shininess ; 

vec4 ComputeLight (vec3 direction, vec4 lightcolor, vec3 normal, vec3 halfvec, vec4 mydiffuse, vec4 myspecular, float myshininess)
{
    float nDotL = dot(normal, direction)  ;         
    vec4 lambert = mydiffuse * lightcolor * max (nDotL, 0.0) ;  

    float nDotH = dot(normal, halfvec) ; 
    vec4 phong = myspecular * lightcolor * pow (max(nDotH, 0.0), myshininess) ; 

    vec4 retval = lambert + phong ; 
    return retval ;
}       

void main (void) 
{       
    if (islight == 0)
    {
		fragColor = vec4(color, 1.0f);
    }
    else
    {
        // The eye is always at (0,0,0) looking down -z axis
        // Also compute current fragment position and direction to eye

        const vec3 eyepos = vec3(0,0,0);
        vec3 mypos = Position.xyz / Position.w ; // Dehomogenize current location
        vec3 eyedirn = normalize(eyepos - mypos);

        // Compute normal, needed for shading.
        vec3 normal = normalize(Normal);

        // Light 0, point
        vec3 position0 = light0posn.xyz / light0posn.w;
        vec3 direction0 = normalize (position0 - mypos) ; // no attenuation
        vec3 half0 = normalize (direction0 + eyedirn);
        vec4 col0 = ComputeLight(direction0, light0color, normal, half0, diffuse, specular, shininess);

        // Light 1, point
        vec3 position1 = light1posn.xyz / light1posn.w;
        vec3 direction1 = normalize (position1 - mypos) ; // no attenuation
        vec3 half1 = normalize (direction1 + eyedirn);
        vec4 col1 = ComputeLight(direction1, light1color, normal, half1, diffuse, specular, shininess);
        
        fragColor = ambient + col0 + col1;
	}
}