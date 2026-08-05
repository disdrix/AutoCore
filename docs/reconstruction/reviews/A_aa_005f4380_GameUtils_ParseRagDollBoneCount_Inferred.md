# Review A (reconstruction fidelity): `aa_005f4380` GameUtils_ParseRagDollBoneCount_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005f4380` |
| **VA** | `0x005f4380`–`0x005f441a` (155 B) |
| **Canonical name** | `GameUtils_ParseRagDollBoneCount_Inferred` |
| **Ghidra name** | `FUN_005f4380` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W27-H) |
| **Counterpart** | `reviews/B_aa_005f4380_GameUtils_ParseRagDollBoneCount_Inferred.md` |
| **System** | GameUtils / ragdoll buffer parse |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `analyze_function_complete`; sole caller `GameUtils_createRagDoll` |
| **Verdict** | **accept** |

---

## 1. Purpose

Ragdoll buffer parse wrapper under `GameUtils_createRagDoll`: construct parse containers, walk tokens via `FUN_005f4230`, return bone/slot count.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005f4380_FUN_005f4380.md` (+ W27-H append) |
| Annotated | `docs/reconstruction/raw/aa_005f4380_FUN_005f4380.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GameUtils_ParseRagDollBoneCount_Inferred.cpp` |
| Clean twin | `FUN_005f4380.cpp` |
| Function | `docs/reconstruction/functions/aa_005f4380_GameUtils_ParseRagDollBoneCount_Inferred.md` |
| Live | decompile ≡ raw; prologue SEH `6A FF 68 E0 79 9A 00`; epilogue `83 C4 28 C3` |
| Caller | `FUN_005f44c0` @ `0x005f45af` (5 pushes; EAX → EDI count) |

---

## 3. Signature (sealed)

```c
// cdecl; EAX count
uint32_t FUN_005f4380(uint32_t p1, uint32_t p2, int p3, uint32_t p4, uint32_t p5);
```

| Formal | Role | Conf |
|---|---|---|
| param_1, param_2 | primary container inputs (`FUN_005f3120`) | **High** |
| param_3 | object with field `+8` for secondary container | **High** |
| param_4, param_5 | forwarded to `FUN_005f4230` | **High** |
| return | bone/slot count | **High** |
| cleanup | plain `RET` (cdecl) | **High** |

---

## 4. Control flow (clean ≡ raw ≡ live)

| Stage | Match | Conf |
|---|---|---|
| SEH install / teardown | **Yes** | **High** |
| Construct primary (`005f3120`) | **Yes** | **High** |
| Construct secondary (`00646d90` from `*(p3+8)`) | **Yes** | **High** |
| Parse count (`005f4230`) | **Yes** | **High** |
| Destroy secondary then primary | **Yes** | **High** |
| Return count | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body **155 B** hex:

```
6aff68e0799a0064a100000000506489250000000083ec1c8b4424308b4c242c535650518d4c2410e873edffff8b5c243c8b43088b54241050528d4c241cc744243400000000e8c52905008b4424448b4c244050518d54241c52c644243801e84cfeffff83c40c8d4c24148bf0c644242c00e8d92905008d4c2408c744242cffffffffe858edffff8b4c24248bc65e5b64890d0000000083c428c3
```

Prologue SEH + `SUB ESP,0x1C`. Epilogue `POP ESI; POP EBX; FS restore; ADD ESP,0x28; RET`.

---

## 6. Gaps

- Nested helpers not dual-sealed (OWN residual).
- Product English for container types / token schema.
- Runtime / differential open.

---

## 7. Verdict

CF/ABI/body size/caller/count role sealed. Name inferred from sole plate-backed parent — acceptable with `_Inferred`. → **accept**.
