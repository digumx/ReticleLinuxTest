#include <iostream>
#include <thread>
#include <pthread.h>
#include <chrono>
#include <reticle.h>

using namespace std;

int main()
{
    RetiRenderer::setReticleRootDirectory("/mnt/data/git-repos/ProjectReticle/Reticle");
    RetiRenderer::init();
    RetiRenderer rendr;

    float verts[] = {1.0, 1.0, 0.0,
                     -1.0, 1.0, 0.0,
                     -1.0, -1.0, 0.0,
                     1.0, -1.0, 0.0};
    float texes[] = {1.0, 1.0,
                    0.0, 1.0,
                    0.0, 0.0,
                    1.0, 0.0};
    unsigned int tris[] = {0, 2, 1, 0, 3, 2};

    RetiMesh mesh(verts, texes, 4, tris, 6);
    mesh.getTransform().translateTransform(0.0, 0.0, -3.0);

    rendr.addMesh(&mesh);

    rendr.startRenderer();

    while(true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
        if (rendr.getKeyboard().isKeyPressed(RetiKey::ESCAPE))  break;
        if (rendr.getKeyboard().isKeyPressed(RetiKey::UP))
            rendr.getCamera().getTransform().translateTransform(0, 0, 0.005);
        if (rendr.getKeyboard().isKeyPressed(RetiKey::DOWN))
            rendr.getCamera().getTransform().translateTransform(0, 0, -0.005);
        if (rendr.getKeyboard().isKeyPressed(RetiKey::LEFT))
            rendr.getCamera().getTransform().rotateTransform(0.005, 0, 1, 0);
        if (rendr.getKeyboard().isKeyPressed(RetiKey::RIGHT))
            rendr.getCamera().getTransform().rotateTransform(-0.005, 0, 1, 0);
    }

    rendr.stopRenderer();
}
