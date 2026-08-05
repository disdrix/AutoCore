# Review A (reconstruction fidelity): `aa_005995a0` Host_ScreenToTerrainHitNotify_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005995a0` |
| **VA** | `0x005995a0` |
| **Body** | sealed **209** B (exclusive end `0x00599671`); Ghidra meta `005995a0`–`00599670` |
| **Canonical name** | `Host_ScreenToTerrainHitNotify_Inferred` |
| **Prior / alias** | `FUN_005995a0` |
| **Review date** | `2026-07-29` (W20-P OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_005995a0_Host_ScreenToTerrainHitNotify_Inferred.md` |
| **System** | world-terrain / screen pick → heightfield hit notify |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `get_function_by_address`, xrefs / complete analysis (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Host **thiscall** (virtual): screen ints → gfxView unproject (`*(map+0xe890)`) → pack float4 → `MarchDirToTerrain` **400** steps → on hit call `*(host+0x24)->vtbl[+0x5c](hit)`; return bool.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005995a0_FUN_005995a0.md` (+ W20-P append) |
| Annotated | `docs/reconstruction/raw/aa_005995a0_FUN_005995a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Host_ScreenToTerrainHitNotify_Inferred.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_005995a0.cpp` |
| Function record | `docs/reconstruction/functions/aa_005995a0_Host_ScreenToTerrainHitNotify_Inferred.md` |
| Live decompile | ≡ raw surface (map gate, unproject, march, notify) |
| Live body bytes | `read_memory` @ `0x005995a0` length 256 |
| Vtbl DATA | `read_memory` `@0x009d55bc` = `0x005995a0` |
| Callee duals | `aa_0075c340` Unproject; `aa_004cff70` MarchDir |

---

## 3. Byte seal (`read_memory` @ `0x005995a0`)

```
55 8b ec 83 e4 f0 83 ec 5c   prolog / align / frame
56 8b f1                     mov esi, ecx          ; host
8b 46 40 85 c0 0f 84 …       map = [esi+0x40]; jz miss
8b 4e 38 8b 56 3c            screen X/Y
…
8b 88 90 e8 00 00            ecx = [map+0xe890]    ; gfxView
e8 …                         call FUN_0075c340
…
68 90 01 00 00               push 400
…
8b 4e 40                     ecx = map
e8 …                         call FUN_004cff70
84 c0 74 14                  test al; jz miss
8b 4e 24 8b 11               ecx = [esi+0x24]; edx = vtbl
8d 44 24 50 50 ff 52 5c      push hit; call [edx+0x5c]
b0 01 … c3                   return 1
32 c0 … c3                   return 0
```

| Claim | Evidence | Conf |
|---|---|---|
| ECX host | `mov esi,ecx` | **High** |
| Map `@+0x40` null gate | `8b 46 40` / jz | **High** |
| Screen `@+0x38/+0x3c` | matching loads | **High** |
| View `map+0xe890` | `8b 88 90 e8 00 00` | **High** |
| maxSteps 400 | `68 90 01 00 00` | **High** |
| March this = map | `8b 4e 40` before call | **High** |
| Notify `+0x24` / `vtbl+0x5c` | `8b 4e 24` / `ff 52 5c` | **High** |
| Bare ret bool | `c3` + AL set | **High** |
| Decompiler drops callee this | surface vs bytes | **High** (bytes win) |
| Vtbl DATA slot | `@0x009d55bc` | **High** |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Map null → 0 | **Yes** |
| Unproject via map view | **Yes** (clean restores this) |
| float4 pack w=0 | **Yes** |
| March 400 | **Yes** |
| Hit → vtbl+0x5c → 1 | **Yes** |
| Miss → 0 | **Yes** |
| No invent drive axes / free | **Yes** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF pipeline | **High** | three-rep + callee duals |
| Host field map | **High** | direct loads |
| Callee identities | **High** | sealed duals |
| Product host class / vfunc name | **Inferred** | no string |
| Hit buffer full schema | **Med residual** | float4 known; 28 B stack |
| Runtime / bit-exact | **Open** | not run |

---

## 6. Gaps

1. Product class of host and notify target; English for vtbl+0x5c.  
2. Hit buffer fields beyond MarchDir float4.  
3. Owning type of vtbl containing `@0x009d55bc`.  
4. Runtime / differential — open.

**Verdict: accept-with-gaps** — CF and host offsets sealed; naming residual.
