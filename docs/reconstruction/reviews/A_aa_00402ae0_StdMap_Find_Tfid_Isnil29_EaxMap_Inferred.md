# Review A (reconstruction fidelity): `aa_00402ae0` StdMap_Find_Tfid_Isnil29_EaxMap_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00402ae0` |
| **VA** | `0x00402ae0`–`0x00402b2f` (**80 B** / `0x50`) |
| **Canonical name** | `StdMap_Find_Tfid_Isnil29_EaxMap_Inferred` |
| **Ghidra name** | `FUN_00402ae0` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY MEGA-083) |
| **Counterpart** | `reviews/B_aa_00402ae0_StdMap_Find_Tfid_Isnil29_EaxMap_Inferred.md` |
| **System** | `interaction-activation` / MSVC map find / TFID-shaped key / isnil@+0x29 |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Exact-match **find** shell over residual lower_bound `FUN_00403e50`: lower_bound then equality gate; write hit node or head(end) to `*outIt`. Shared client map helper (often `client+0xd24` / global `0x00d1b564`); **not** respawn-only despite parent-chain scaffold name.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ MEGA-083 append) | `docs/reconstruction/raw/aa_00402ae0_FUN_00402ae0.md` |
| Annotated | `docs/reconstruction/raw/aa_00402ae0_FUN_00402ae0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdMap_Find_Tfid_Isnil29_EaxMap_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_00402ae0.cpp` |
| Function record | `docs/reconstruction/functions/aa_00402ae0_StdMap_Find_Tfid_Isnil29_EaxMap_Inferred.md` |
| Twin (ABI-different) | dualed `aa_004cba00` StdMap_Find_Tfid_Isnil29_Inferred (WQ9G-G) |
| Live | decompile ≡ equality CF; RET 4 + body hex sealed |

---

## 3. Signature (sealed)

```c
// EAX = map (head@+4); EDI = pKey; stack outIt*; RET 4; *outIt written
Node** StdMap_Find_Tfid_Isnil29_EaxMap_Inferred(
    MapHost_Head4* map, const KeyU32I32* pKey, Node_Isnil29** outIt);
```

| Formal | Source | Conf |
|---|---|---|
| map | **EAX** (`MOV ESI,EAX`) | **High** |
| pKey | **EDI** (`MOV EDX,EDI` before CALL) | **High** |
| outIt | stack → EBX (`MOV EBX,[ESP+0xC]`) | **High** |
| cleanup | `C2 04 00` both exits | **High** |
| effect | `*outIt = node or head`; EAX=outIt | **High** |

---

## 4. Control flow

```
lb = LowerBound_Isnil29(map=EAX, key=EDI)   // FUN_00403e50
head = map->head
if lb != head && node.key <= *pKey:  // hi signed @+0x14, lo unsigned @+0x10
  *outIt = lb
else:
  *outIt = head
return outIt
```

| Stage | Match | Conf |
|---|---|---|
| lower_bound call | `CALL 00403e50` | **High** |
| end test | `CMP EAX, [map+4]` | **High** |
| key gate hi/lo | JL/JG then JC bytes | **High** |
| no mutate | no stores to tree | **High** |
| RET 4 | both epilogues | **High** |
| live decompile ≡ raw CF | yes | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (80 B) — see raw MEGA-083 append. Next function @ `0x00402b30`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker (find shell) |
| Xrefs | 5 UNCONDITIONAL_CALL |
| Callers | `Client_SendRespawnInSector`, `FUN_00944d50`, `Client_Input_OnKeyDown_MatchAction`, `FUN_0091da70`, site `0x00957e3a` |
| Callee | `FUN_00403e50` only (residual) |
| Closes | Named_CalleeOf SendRespawn scaffold residual for `0x00402ae0` |

### Call-site ABI corroboration

| Site | Map | Key |
|---|---|---|
| `00935340` | `LEA EAX,[ESI+0xd24]` | `LEA EDI,[…+0x164]` TFID |
| `00944e4b` | `LEA EAX,[EBX+0xd24]` | `LEA EDI,[EBP+0x160]` |
| `0091120a` | `MOV EAX,0xd1b564` | TFID via `…+0x164` |
| `0091df4e` | `MOV EAX,0xd1b564` | `LEA EDI,[…+0x164]` |
| `00957e3a` | `LEA EBX,[EBP+0xd24]` then `MOV EAX,EBX` | `LEA EDI,[…+0x164]` |

---

## 7. Gaps

- Product map / value_type English at node `+0x20`.
- Residual lower_bound `FUN_00403e50` not dualled (exclusive VA).
- Whether all hosts share one class vs layout clones.
- Runtime / bit-exact / differential.

---

## 8. Verdict

Fidelity pass seals CF/ABI/key layout/find role and retires Named_CalleeOf scaffold. Product English residual → **accept-with-gaps**.
