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

    //RetiMesh mesh(verts, texes, 4, tris, 6);
    //mesh.getTransform().translateTransform(0.0, 0.0, -3.0);

    RetiSceneObject obj("/mnt/data/3DModels/Jug/Milk jug.3DS");
    obj.getTransform().scaleTransform(0.2, 0.2, 0.2);
    obj.getTransform().translateTransform(-1, -1, -3);

    rendr.addSceneObject(&obj);

    rendr.startRenderer();

    std::this_thread::sleep_for(std::chrono::seconds(5));

    rendr.stopRenderer();
}
