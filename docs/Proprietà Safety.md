>i processi non devono "interferire" fra di loro nell'accesso alle risorse condivise 
>questo vale ovviamente per i processi che condividono risorse (non per processi che cooperano tramite comunicazione)

I meccanismi di sincronizzazione servono a garantire la [[Proprietà Safety]]
Devono essere usati propriamente dal programmatore, altrimenti il programma potrà contenere della[[Race Condition]].