
asm(".global sceM4aacEncClearContext\n"
    ".type sceM4aacEncClearContext @function\n"
    "sceM4aacEncClearContext:\n");

asm(".global sceM4aacEncCreateEncoder\n"
    ".type sceM4aacEncCreateEncoder @function\n"
    "sceM4aacEncCreateEncoder:\n");

asm(".global sceM4aacEncDeleteEncoder\n"
    ".type sceM4aacEncDeleteEncoder @function\n"
    "sceM4aacEncDeleteEncoder:\n");

asm(".global sceM4aacEncEncode\n"
    ".type sceM4aacEncEncode @function\n"
    "sceM4aacEncEncode:\n");

asm(".global sceM4aacEncEncodeWithPriority\n"
    ".type sceM4aacEncEncodeWithPriority @function\n"
    "sceM4aacEncEncodeWithPriority:\n");

asm(".global sceM4aacEncFlush\n"
    ".type sceM4aacEncFlush @function\n"
    "sceM4aacEncFlush:\n");

asm(".global sceM4aacEncFlushWithPriority\n"
    ".type sceM4aacEncFlushWithPriority @function\n"
    "sceM4aacEncFlushWithPriority:\n");
