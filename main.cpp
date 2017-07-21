#include <iostream>
#include <thread>
#include <cmath>
#include <pthread.h>
#include <chrono>
#include <reticle.h>

/// Uncomment to parent camera to obj.
#define PARENT_CAM

/** Note, for best results, activate only one of the following 3 macros at a time. */

/** Uncomment to test global vs local rotations*/
#define TEST_LOCAL_ROTATION

/** Uncomment to test global vs local scale*/
//#define TEST_LOCAL_SCALE

/** Uncomment to test global vs local scale*/
//#define TEST_LOCAL_TRANSLATION


using namespace std;

int main()
{
    RetiRenderer::setReticleRootDirectory("/mnt/data/Dev/git-reticle/ProjectReticle/Reticle");
    RetiRenderer::init();
    RetiRenderer rendr;

    RetiSceneObject obj("/home/digumx/Models/jug2.3DS");

    rendr.addSceneObject(&obj);
    obj.getTransform().scaleTransform(20, 20, 20);
    obj.getTransform().translateTransform(0, -2, -10);

    RetiSceneObject obj2("/home/digumx/Models/Chair/Armchair.3DS");

    rendr.addSceneObject(&obj2);
    obj2.getTransform().translateTransform(0, -4, -30);
    obj2.getTransform().scaleTransform(0.1, 0.1, 0.1);

    #ifdef PARENT_CAM
    rendr.getCamera().getTransform().setParent(obj.getTransform());
    #endif // PARENT_CAM

    #ifdef TEST_LOCAL_ROTATION
    obj.getTransform().rotateTransform(1.57, 0, 0, 1);
    #endif // TEST_LOCAL_ROTATION

    #ifdef TEST_LOCAL_SCALE

    /// Comment the following line to try different orientations.
    obj.getTransform().rotateTransform(-1.57, 0, 0, 1);
    obj.getTransform().scaleTransformLocal(1, 10, 1);

    #endif // TEST_LOCAL_SCALE

    #ifdef TEST_LOCAL_TRANSLATION

    /// Comment the following line to try different orientations.
    obj.getTransform().rotateTransform(1.57, 0, 0, 1);
    obj.getTransform().translateTransform(1, 10, 1);

    #endif // TEST_LOCAL_TRANSLATION


    rendr.startRenderer();

    rendr.getKeyboard().addKeyListener(RetiKey::ENTER);
    rendr.getKeyboard().addKeyListener(RetiKey::UP);
    rendr.getKeyboard().addKeyListener(RetiKey::DOWN);
    rendr.getKeyboard().addKeyListener(RetiKey::LEFT);
    rendr.getKeyboard().addKeyListener(RetiKey::RIGHT);
    rendr.getKeyboard().addKeyListener(RetiKey::W);
    rendr.getKeyboard().addKeyListener(RetiKey::S);

    while(true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(5));

        #ifdef TEST_LOCAL_ROTATION

        /** Change rotateTransformLocal to rotateTransform to see global rotation */
        obj.getTransform().rotateTransformLocal(0.003, 0, 1, 0);

        #endif // TEST_LOCAL_ROTATION


        if(rendr.getKeyboard().isKeyPressed(RetiKey::ENTER))
            break;
        if(rendr.getKeyboard().isKeyPressed(RetiKey::UP))
        {
            rendr.getCamera().getTransform().translateTransformLocal(0, 0, -0.009);

            /** Uncomment the following, build, run and move in the forward direction. If indeed
            *   camera transform is not inverted, the cup should not move in view space.
            */
            ///obj.getTransform().translateTransform(0, 0, -0.009);
        }
        if(rendr.getKeyboard().isKeyPressed(RetiKey::DOWN))
            rendr.getCamera().getTransform().translateTransformLocal(0, 0, 0.009);
        if(rendr.getKeyboard().isKeyPressed(RetiKey::LEFT))
            rendr.getCamera().getTransform().rotateTransformLocal(0.009, 0, 1, 0);
        if(rendr.getKeyboard().isKeyPressed(RetiKey::RIGHT))
            rendr.getCamera().getTransform().rotateTransformLocal(-0.009, 0, 1, 0);
        if(rendr.getKeyboard().isKeyPressed(RetiKey::W))
            rendr.getCamera().getTransform().rotateTransformLocal(0.009, 1, 0, 0);
        if(rendr.getKeyboard().isKeyPressed(RetiKey::S))
            rendr.getCamera().getTransform().rotateTransformLocal(-0.009, 1, 0, 0);

    }

    rendr.stopRenderer();
}
