# Raw capture: TFID_NotEquals

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040b150` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0040b150` |
| **Body end** | `0x0040b188` |
| **Canonical name** | `TFID_NotEquals` |
| **System** | `tfid-identity` |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int __cdecl TFID_NotEquals(void *pA,void *pB)

{
  if (((*(int *)pA == *(int *)pB) && (*(int *)((int)pA + 4) == *(int *)((int)pB + 4))) &&
     (*(char *)((int)pA + 8) == *(char *)((int)pB + 8))) {
    return 0;
  }
  return 1;
}
```

---

## v2026-07-29 dual residual (append-only)

| Field | Value |
|---|---|
| **Tool** | Ghidra MCP `decompile_function` + `read_memory` + `get_function_by_address` |
| **Program** | `autoassault.exe` |
| **Live decompile** | Identical to raw body above |
| **Body range** | `0040b150` – `0040b188` (ret) |

### Body bytes (length 64; first 57 = code through final `ret`, then `CC` pad)

```
8b 44 24 04 8b 10 8b 4c 24 08 3b 11 75 1f 8b 50
04 3b 51 04 75 17 8a 40 08 3a 41 08 75 0f b8 01
00 00 00 33 c9 84 c0 0f 94 c1 8a c1 c3 33 c0 33
c9 84 c0 0f 94 c1 8a c1 c3 cc cc cc cc cc cc cc
```

### Twin Equals body (`0x00404aa0`, for polarity contrast)

```
8b 44 24 04 8b 10 8b 4c 24 08 3b 11 75 16 8b 50
04 3b 51 04 75 0e 8a 40 08 3a 41 08 75 06 b8 01
00 00 00 c3 33 c0 c3
```

### Callers (Ghidra `get_function_callers`, limit 50 — 24 returned)

```
CVOGCreature_PostCreateFromPacket @ 004c5c30
Client_RecvGroupReactionCall @ 008092a0
Client_RecvSkillStatusEffect @ 00811170
Client_Skill_ResolveCastTarget @ 0093b3a0
FUN_004ca150 @ 004ca150
FUN_004ca760 @ 004ca760
FUN_004d1d00 @ 004d1d00
FUN_00515520 @ 00515520
FUN_00525cc0 @ 00525cc0
FUN_0058c3b0 @ 0058c3b0
FUN_005cebd0 @ 005cebd0
FUN_005da0a0 @ 005da0a0
FUN_0061db60 @ 0061db60
FUN_0061fdf0 @ 0061fdf0
FUN_007ffef0 @ 007ffef0
FUN_008093c0 @ 008093c0
FUN_00836410 @ 00836410
FUN_00921f70 @ 00921f70
FUN_0093e450 @ 0093e450
FUN_00945540 @ 00945540
NPC_TryCastSkillFromSet @ 005d1280
Skill_FilterTargetForResolveList_Inferred @ 0054ff00
Skill_LocalCastValidate @ 0051a790
VehicleNet_ReconcilePrediction @ 005f9f10
```
