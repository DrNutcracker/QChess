#version 450 core	//can lower version if not supported

layout(location = 0) in vec3 in_position; //set the first input on location (index) 0, in_position is the attribute 
layout(loaction = 1) in vec4 in_color;

out vec4 color;

void main()
{
	color = in_color;
	gl_Position = vec4(in_position, 1); //w is 1.0, also cast to vec4
}