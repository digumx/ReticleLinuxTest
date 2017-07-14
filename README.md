# ReticleLinuxTest
A little test repository to test Reticle on a linux platform.

This repository is basically a Code::Blocks project, and will probably be so in the foreseeable future.

## License:

This project is licensed under the MIT License.

## Usage:

 -  Install all dependencies of reticle. 
 -  Install Reticle itself.
 -  Clone/Fork/Download to get a local copy of this repository.
 -  Open the .cbp file and make sure that all absolute and relative paths in the Build Options correctly point to the Reticle root directory (which should contain the Sources, Headers, Dependencies, etc).
 -  Find the line that says `RetiRenderer::setReticleRootDirectory("...")` and replace `"..."` with absolute or CWD-relative path to Reticle root directory.
 -  Enjoy!:)
