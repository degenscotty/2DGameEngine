# SDL Engine

A 2D Game Engine made for an assignment at DAE (howest) Kortrijk.

I started the engine from scratch following TheCherno on youtube! Big thanks to him!

## 3rd Party Libraries
 - [SDL2](https://www.libsdl.org/download-2.0.php)
 - [SDL2_image](https://www.libsdl.org/projects/SDL_image/)
 - [SDL2_ttf](https://www.libsdl.org/projects/SDL_ttf/)
 - [glm](https://github.com/g-truc/glm)
 - [spdlog](https://github.com/gabime/spdlog)
 - [FMOD](https://www.fmod.com/download)

════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════

Link to GitHub Repository: https://github.com/scottvermast/2DGameEngine

════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════
────────────────┐
Order of Events │
────────────────┘

						InputManager::Update()
							║
							▼
						SceneManager::Update()
							║
							▼
				            	Renderer::ClearBuffer
							║
							▼
					    	SceneManager::Render()
							║
							▼
					    	Renderer::Render()

════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════
──────────────┐
InputManager  │ 
──────────────┘	

Input is rather simple in PEngine. I used arrays of bools. These get set to true if an SDL_event would trigger them ofcourse.

════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════
──────────────┐
SceneManager  │
──────────────┘	

The Scenemanager can hold mutiple Scenes. These Scenes can hold multiple GameObjects. These GameObjects can hold multiple Components.
But the Scenemanager is the root of it all which initializes, updates and makes sure everything renders without any issues.

The Scenemanager is also the one who controls which scene will be active. Any non-active scenes will just be on "pause".

════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════						
─────────┐
Renderer │  
─────────┘		
		
The Renderer doesn't do any tricky stuff. All GameObjects can have TextureComponents or TextComponents or..
They all just copy their data to the buffer. After all the data has arrived.. SDL_RenderPresent();

The Renderer also has functions like RenderTexture() or RenderText() so you don't necessarily need components to do the job.

						
════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════					
────────────┐
Resources   │
────────────┘				

I'm using a ResourceManager that holds 2 unordered_maps.

std::unordered_map<std::string, Texture2D*> m_Textures;
std::unordered_map<std::pair<std::string, unsigned int>, Font*, pair_hash> m_Fonts;

The Texture map's key is just the name of the file which makes it very convenient and easy to use.
The second map that holds all the fonts was a bit trickier cause a font doesn't only have a filename but a size too!
So the key for the second map is a pair, for which I wrote a hashfunction that XORs the filename with the size.

════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════
─────────────────┐
GarbageCollector │   
─────────────────┘	

The GarbageCollector is something I started making with a friend for GP2. It adds a pointer of the object to delete
to one of it's vectors. Then at the start of the next UpdateLoop in the SceneManager it deletes the object from the scenegraph
and from the heap ofcourse to prevent any memory leaks from happening. So far I've had 0 trouble with memory leaks.
						
════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════						
──────────────┐
SoundManager  │ 
──────────────┘				

I used FMOD for sound. It's pretty straightforward. You load your sound. Give it an ID. And you can play it anywhere in your code
using that ID. Simple but very effective.

════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════
─────────┐
Logging  │
─────────┘

I used spdlog to help make a nice clean logger.
I made easy macro's in which you can easily pass in variables.

#define CORE_ERROR(...)	::Log::GetCoreLogger()->error(__VA_ARGS__);
example: CORE_ERROR("SDL_Window could not be created :: {0}", SDL_ERROR);

Very easy to use and available everywhere in your code.

[credits to TheCherno]

════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════					
────────────┐
Components  │
────────────┘	

TransformComponent:	All around positioning and rotations for every GameObject.

			GetPosition()
			GetRotation()
			etc..
			
TextureComponent:  		If you'd wanna give your GameObjects a .png or a .jpg you'd wanna use this one.

TextComponent:			Use this one to add Text to any GameObject.

SpriteComponent:		This is the same as a TextureComponent but with some animation capabilities.

CollisionComponent: 	A CollisionComponent basically holds a rectangle (pos.x, pos.y, width, height).
						An active Scene checks if either of those components are colliding with eachother.
						If they do, this triggers a FunctionCallback to the GameObjects in question.
						So you can just add an OnTrigger(GameObject* gameObject) to any GameObject.
						These CollisionComponents also are gathered in a PhysicsSystem class which checks if
						the GameObjects in question have to be put back in place using minowski AABB collision detection.
			
BubbleComponent:		Component which will make any object float like if it was caught in a bubble.
						Used in bubble bobble ofcourse to have the right behavior for the bubbles that bobble shoots.
					
ButtonComponent:		Allows you to add a button to any GameObject you want.

FPSComponent: 			Makes the client FPS visisble.

StateComponent: 		Holds a map containing states. There can only be 1 active state at once. The current state updates.

RigidbodyComponent:		Adds gravity to any GameObject in your scene.

ControllerComponent:	Used to interact with the players inputcommands, can be used by AI too.
						Is in direct communication with the rigidbody components to allow smooth velocity changes (movement, including running, jumping etc..)
						
════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════						

