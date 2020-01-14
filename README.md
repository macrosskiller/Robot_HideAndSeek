# Robot_HideAndSeek
Cache-cache dans une pièce contre un robot.

On présente un objet à la caméra, un apprentissage de l'objet est fait par le système.
Une fois l'apprentissage fait, nous avons un temps donné pour cacher l'objet dans la pièce.
Dès que ce temps est écoulé, le système se mets à chercher l'objet grâce au flux vidéo de la caméra.
Le système possède un axe sur lequel la caméra peut s'orienter.



La librairie qui sera utilisé sera OpenCV.
Le langage utilisé sera C++.

Matériel nécessaire :
- caméra type raspberry
- raspberry pi
- jetson nano
- servomoteur(s)
- carte interface I2C/PWM
- support mécanique
- alimentation externe pour le(s) servomoteur(s)
- objets à détecter
