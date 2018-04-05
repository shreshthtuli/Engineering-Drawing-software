# version 330 core
// modern OpenGL is used, your OpenGL version should
// be at least 3.1 (corresponding to GLSL version 140, which somehow has forward
// compatibility to the above listed version 330). Do NOT change the version
// directive to "version 140" or "version 150," as the shader will fail (due to modern
// OpenGL not yet being core at that point in time).

// Since modern OpenGL does not maintain buffers for vertex positions, normals, colors,
// materials, etc., the user must use vertex buffer objects (VBOs) to pass this information
// onto the vertex shader. If multiple VBOs are used, the layout location should be specified
// with glVertexAttribPointer so that the vertex shader knows exactly what position in
// memory each variable occupies.
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;

// In modern OpenGL, the graphics library no longer maintains a matrix stack for the
// user. Consequently, matrices such as the projection, model, view, etc. must be
// passed into the shader, via the "uniform" keyword. Uniform variables are accessible
// in both the vertex and fragment shaders.
uniform mat4 projection;
uniform mat4 modelview;

// The default output of the vertex shader is gl_Position.
// Other outputs of the vertex shader can be defined with the keyword "out", which
// become the inputs (with the same variable name) of the fragment shader.
out vec3 Normal; 
out vec4 Position;

void main()
{
    gl_Position = projection * modelview * vec4(position, 1.0f);
    Normal = mat3(transpose(inverse(modelview))) * normal; 
    Position = modelview * vec4(position, 1.0f);
}