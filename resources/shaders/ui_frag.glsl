#version 330 core

// layout (location = 3) in float isCharOut_f;

uniform sampler2D charTexture;

in vec3 colorUpdated;
in vec2 TexCoord;

in float isCharOut_f;


out vec4 FragColor;

void main()
{
    // debug - render
    int debug = 1;
    vec3 isCharColor = vec3(isCharOut_f*0.5, isCharOut_f*0.5, isCharOut_f*0.5);

    if(debug == 0){
        if(isCharOut_f > 0.5 && isCharOut_f < 1.5){
            FragColor = vec4(isCharColor, 1.0f);
        }
        else if(isCharOut_f > 1.5){
            FragColor = vec4(isCharColor, 1.0f);
        }
        else{
            FragColor = vec4(isCharColor, 1.0f);
        }
    }
    else{

        if(isCharOut_f > 0.5 && isCharOut_f < 1.5){
            FragColor = texture(charTexture, TexCoord);
        }
        else if(isCharOut_f > 1.5){
            FragColor = texture(charTexture, TexCoord);
        }
        else{
            FragColor = vec4(colorUpdated, 1.0f);
        }
    }

    

    // FragColor = vec4(elementColor, 1.0f);
}
