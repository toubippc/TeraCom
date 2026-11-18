# Notes de Copilot pour ce projet

- Dans les pages HTML embarquées, comme `include/html/index_html.h`, les valeurs CSS en pourcentage doivent conserver deux signes `%` (par exemple `width: 100%%` ou `border-radius: 50%%`). C'est la convention de traduction utilisée par le projet : ne pas les remplacer par un seul `%`.
- Pour les changements d'interface, ne pas ajouter de comportement fonctionnel sans demande explicite.
- Courbe de température — décision à reprendre avec l'utilisateur : en mode normal, il choisit la température cible et la durée, et le coefficient est calculé. En mode avancé, modifier le coefficient doit garder la cible fixe et recalculer/afficher la durée nécessaire. La température cible ne doit jamais changer silencieusement.

#TODO 

— Quand le nombre ou la complexité des états, préréglages et actions sur les sorties augmentera, envisager une classe dédiée pour les modéliser. L'ECU est un préréglage d'urgence (notamment ventilation active selon sa configuration), pas un arrêt général. C'est plutot une configuration de mise en sécurité de l'animal/environnement
