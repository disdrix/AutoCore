# Review A (reconstruction fidelity): `aa_005cedf0` CVOGHBAI_UpdateAimOffset_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005cedf0` |
| **VA** | `0x005cedf0`–`0x005cf558` (1897 B) |
| **Canonical name** | `CVOGHBAI_UpdateAimOffset_Inferred` |
| **Ghidra name** | `FUN_005cedf0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W26-O) |
| **Counterpart** | `reviews/B_aa_005cedf0_CVOGHBAI_UpdateAimOffset_Inferred.md` |
| **System** | HB AI aim-offset |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` |
| **Verdict** | **accept** |

---

## 1. Purpose

Worker **AI aim-offset state machine** on ECX object:

1. Clear if owner/phys missing.
2. Convert client tick ms → seconds.
3. Clear active offset on TTL **6 s** or owner near stored aim (**0.75**).
4. When still (≤**0.05** vs last sample) but active pose drifted (>**1**), arm timer; after **1.5 s** build randomized local offset, transform by pose object@`+0x18`, store aim@`+0x40`.
5. Non-finite delta → `g_abInferredDefaultAimPos`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005cedf0_FUN_005cedf0.md` (+ W26-O append) |
| Annotated | `docs/reconstruction/raw/aa_005cedf0_FUN_005cedf0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBAI_UpdateAimOffset_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005cedf0.cpp` |
| Function | `docs/reconstruction/functions/aa_005cedf0_FUN_005cedf0.md` |
| Named | `docs/reconstruction/functions/aa_005cedf0_CVOGHBAI_UpdateAimOffset_Inferred.md` |
| Live | decompile ≡ raw CF; body end `C3` @ `0x005cf558`; pad `CC` |
| Constants | `read_memory` on all DAT_* listed in raw append |

---

## 3. Signature (sealed)

```c
void __fastcall CVOGHBAI_UpdateAimOffset_Inferred(void *this /* ECX */);
```

| Claim | Conf |
|---|---|
| ECX this (`param_1`) | **High** — `MOV ESI,ECX` body uses ESI fields |
| void / no stack formals | **High** — plain RET |
| Worker classification | **High** — 5+ named callees + vtbls |

---

## 4. Control flow (clean ≡ raw ≡ live)

| Stage | Match | Conf |
|---|---|---|
| Owner/phys fail → clear | **Yes** | **High** |
| Tick ms → seconds (+2^32 bias) | **Yes** | **High** |
| Active TTL 6.0 / near 0.75 clear | **Yes** | **High** |
| Candidate phys/combat gate | **Yes** | **High** |
| Still eps 0.05 | **Yes** | **High** |
| Pose drift > 1.0 arm/hold/build | **Yes** | **High** |
| Wait 1.5 before build | **Yes** | **High** |
| Random local XZ + quat transform | **Yes** | **High** |
| Default aim fallback | **Yes** | **High** |
| Decompile unreachable warning | noted | n/a |

---

## 5. Constants (`read_memory`)

| Const | Value | Role |
|---|---|---|
| `DAT_00aaa8dc` | 6.0 | active TTL |
| `DAT_00a0f708` | 0.75 | near-clear |
| `DAT_00a10e78` | 0.05 | still gate |
| `DAT_00aaa68c` | 1.5 | arm delay |
| `DAT_00aaa688` / `690` | 5.0 / 4.0 | random bases |
| `_DAT_009da8cc/d0` | ≈5/65535, 6/65535 | ushort scales |
| `DAT_00aaa668` | −1.0 | sign flip |
| `_DAT_00aaa5dc` | 2^32 | uint float bias |

---

## 6. Gaps

- Product class name of `this` (inferred AI aim helper).
- Full duals for `FUN_005d1d20` / `FUN_005d6870` (not OWN).
- Consumer of aim@`+0x40` (shoot/look) — caller domain.
- RNG stream bit-exact / runtime — open.
- Ghidra unreachable block `0x005cf409` — dead; CF of live paths sealed.

---

## 7. Verdict

CF/ABI/constants/call graph sealed → **accept** (inferred name retained).
