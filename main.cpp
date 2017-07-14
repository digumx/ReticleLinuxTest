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

    float verts[] = {1.0, 1.0, 0.0,
                     -1.0, 1.0, 0.0,
                     -1.0, -1.0, 0.0,
                     1.0, -1.0, 0.0};
    float texes[] = {1.0, 1.0,
                    0.0, 1.0,
                    0.0, 0.0,
                    1.0, 0.0};
    unsigned int tris[] = {0, 1, 2, 0, 2, 3};

    RetiMesh mesh(verts, texes, 4, tris, 2);
    mesh.getTransform().translateTransform(0.0, 0.0, 1.0);

    RetiRenderer rendr;
    rendr.addMesh(&mesh);

    rendr.startRenderer();

    std::this_thread::sleep_for(std::chrono::seconds(20));

    rendr.stopRenderer();
}
