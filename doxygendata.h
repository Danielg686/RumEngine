/// \defgroup RUMENGINE-API RumEngine API
///\brief Commands available to all RumEngine users.

///\defgroup GAMEOBJECT GameObject 
///\ingroup RUMENGINE-API
///\brief All game entities will be derived from GameObject.

///\defgroup DEFAULTEVENTS Default Events
///\ingroup GAMEOBJECT
///\brief Events that all GameObjects are automatically registered to receive.

///\defgroup EXTRAFEATURES Extra Features
///\brief Features of the Game Engine

///\defgroup INPUTABLE Inputable
///\ingroup GAMEOBJECT
///\brief Callbacks associated with window, keyboard, mouse and game controllers events. *IMPORTANT*:
///In order for any of these callbacks to be activated, the
///GameObject must be registered using the this->SubmitKeyRegistration function and the associated InputFlags.
///		\code 
///			Tank::Tank()
///			{	
///				this->SubmitKeyRegistration(AZUL_KEY::KEY_SPACE, INPUT_EVENT_TYPE::KEY_PRESS);
///			}
///		\endcode


///\defgroup ALARMABLE Alarmable
///\ingroup GAMEOBJECT
///\brief Each object derived from Alarmable has up to 3 alarms available to it which trigger a callback
///to execute user defined code.
///		\code
///			Spaceship::Spaceship()
///			{
///				this->SubmitAlarmRegistration0(2.0f);       //registers Spaceship's alarm 0 for 2 seconds.
///			}
///
///			void Spaceship::Alarm0()
///			{
///				playsound();	//will execute this command after 2 seconds from Registration has passed.
///			}
///		\endcode

///\defgroup COLLIDABLE Collidable
///\ingroup GAMEOBJECT
///\brief Each object from Collidable that you want the collision system to recognize a collision with another 
///object must be registered for each collision pair.
///		\code
///			SceneDemo::Initialize()
///			{
///				SetCollisionSelf<Tank>();
///				SetCollisionSelf<Cottage>();
///				SetCollisionPair<Tank, Cottage>();
///			}
///
///
///			Tank::Tank()
///			{
///				this->CollisionRegistration<Tank>(this);  //Registers tank as a collidable object within the system.
///			}
///			void Tank::Collision(Tank*)
///			{
///				// do something when this Tank collides with another Tank
///			}
///			void Tank::Collision(Cottage*)			
///			{
///				// do something when this Tank collides with a Cottage.
///			}
///
///			Cottage::Cottage()
///			{
///				this->CollisionRegistration<Cottage>(this);
///			}
///			void Cottage::Collision(Tank*)
///			{
///				// do something when a Tank collides with this Cottage.
///			}
///		\endcode
///	

///	\defgroup DRAWABLE Drawable
///	\ingroup GAMEOBJECT
///	\brief GameObjects inherit from Drawable and the Draw function should be used to render objects within the class.
///		\code
///			Tank::Tank()
///			{
///				this->SubmitDrawRegistration(); //object will be drawn every frame in the user defined Tank::Draw() function
///			}
///		\endcode

///	\defgroup DRAWABLE2D Drawable2D
///	\ingroup GAMEOBJECT
///	\brief GameObjects inherit from Drawable2D and the Draw2D function should be used to render 2D or Sprite objects within the class.
///		\code
///			Sprite::Sprite()
///			{
///				this->SubmitDraw2DRegistration(); //object will be drawn every frame in the user defined Sprite::Draw2D() function
///			}	
///		\endcode

///	\defgroup SCENE Scene
/// \ingroup RUMENGINE-API
///	\brief A Scene is a space to define a GameObject.
///	
///Scenes can act as levels and can be changed. When deriving from Scene the Initialize function is the only function that 
///needs to be implemented as it is called when creating a new Scene. 
///			
///

/// \defgroup RESOURCES Resources
/// \ingroup RUMENGINE-API
///	\brief Tool used to load resources at startup, this includes Models, Shaders, Textures
///LoadAllResources.cpp contains one function which should be used to import resources.
///		\code
///			void RumEngine::LoadAllResources()
///			{
///				ModelManager::Load("Tank", "MC1"); //loads MC1.Azul model into the ModelManager, "Tank" can be used to reference this model.
///				TextureManager::Load("Tank1", "MC11"); //loads MC11.tga Texture in the TextureManager, "Tank1" can be used to reference this Texture.
///				ShaderManager::Load("pShaderObject_texture", "textureFlatRender"); //loads GLSL shader file into the ShaderManager,  "pShaderObject_texture" can be used to refernece this Shader.
///			
///				SceneManager::SetStartScene(new SceneDemo()); //Loads a user defined class, derived from the Scene class as the start scene for the game.
///			}
///		\endcode
///

///
///
///
///
///
///
///
///