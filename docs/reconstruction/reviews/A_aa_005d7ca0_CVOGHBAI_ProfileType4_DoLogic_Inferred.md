# Review A (reconstruction fidelity): `aa_005d7ca0` CVOGHBAI_ProfileType4_DoLogic_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d7ca0` |
| **VA** | `0x005d7ca0`–`0x005d7dd0` |
| **Canonical name** | `CVOGHBAI_ProfileType4_DoLogic_Inferred` |
| **Ghidra name** | `FUN_005d7ca0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W27-I) |
| **Counterpart** | `reviews/B_aa_005d7ca0_CVOGHBAI_ProfileType4_DoLogic_Inferred.md` |
| **System** | npc-ai / HBAI / profile-type-4 |
| **Evidence pass** | Live `decompile_function` + `read_memory` + `analyze_function_complete`; DATA vtbl `@0x009db0dc`; twins Driver/CreatureBase DoLogic; sealed map + aim duals |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Per-tick combat/logic for the HBAI subclass whose vtbl is `PTR_FUN_009db08c` (factory profile type word **4**): profile lower_bound, clear `owner+0x278`, binary state on `owner+0x26c`, skill sets 0/2, aim update, busy/path gates, pursue, vtbl tails.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005d7ca0_FUN_005d7ca0.md` (+ W27-I append) |
| Annotated | `docs/reconstruction/raw/aa_005d7ca0_FUN_005d7ca0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGHBAI_ProfileType4_DoLogic_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005d7ca0.cpp` |
| Function | `docs/reconstruction/functions/aa_005d7ca0_CVOGHBAI_ProfileType4_DoLogic_Inferred.md` |
| Twin DoLogic | `CVOGHBAIDriver_DoLogic` / `CVOGHBAICreatureBase_DoLogic` |
| Sealed callees | `00540890`, `004cbd50`, `005cedf0` duals |
| Vtbl | `0x009db0dc` in `009db08c` (ctor `FUN_005d7de0`) |

---

## 3. Signature

```c
// Ghidra: void __fastcall FUN_005d7ca0(int *param_1)
// Bytes: sub esp,8; push esi; mov esi,ecx … add esp,8; ret
void __thiscall CVOGHBAI_ProfileType4_DoLogic_Inferred(int *self);
```

| Item | Evidence | Conf |
|---|---|---|
| thiscall ECX=this | `8B F1` | **High** |
| bare ret / void | tail `C3` | **High** |
| Class = type-4 HBAI | vtbl `009db08c` only xref | **High** |
| Method name DoLogic | structural twin of Driver::DoLogic; **no** in-body plate | **Probable** |

---

## 4. Control flow (sealed)

1. Key from owner MI → def `+0x4DC`; map get + lower_bound; **return if end**.
2. `FUN_004c3c80(owner, 0)` → `owner+0x278 = 0`.
3. **owner+0x26c == 0:** cast set **0**; aim; if path byte clear: busy? ret; vtbl `+0x1C`; target → vtbl `+0x2C`(2); `FUN_005cebd0(0)`? ret; vehicle/object `+0x1A0` → this vtbl `+0x4C`.
4. **owner+0x26c != 0:** cast set **2**; aim; if path clear: busy? ret; target → `FUN_005cf560`; if target remains return; else vtbl `+0x2C`(0).
5. **Fallthrough:** `FUN_005cc450` when path-mode byte non-zero after cast/aim.

| Stage | Match | Conf |
|---|---|---|
| Profile lower_bound early-out | **Yes** | **High** |
| owner+0x26c binary (not ternary) | **Yes** | **High** |
| Skill sets 0 / 2 only | **Yes** | **High** |
| Aim update both arms | **Yes** (`005cedf0`) | **High** |
| Pursue in non-zero arm | **Yes** (`005cf560`) | **High** |
| No FireWeapons tail | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

| Addr | Bytes | Decode |
|---|---|---|
| `0x005d7ca0` | `83 EC 08 56 8B F1` | prolog; ESI=this |
| owner load | `8B 46 64` | `mov eax,[esi+0x64]` |
| host ECX | `8B 0D FC 41 B0 00` | `DAT_00b041fc` |
| clear flag | `8B 4E 64 6A 00 E8 …` | `FUN_004c3c80(owner,0)` |
| state test | `80 B8 6C 02 00 00 00` | `cmp byte [eax+0x26c],0` |
| tail | `5F 5E 83 C4 08 C3` | bare ret |

Body **305 B**; pad `CC` after `0x005d7dd0`.

---

## 6. Gaps

- Product class name for `PTR_FUN_009db08c` / profile type 4.
- Product method plate (DoLogic inferred).
- Nested `FUN_005cc980` / `FUN_005cebd0` / `FUN_005cc450` not OWN.
- Runtime / bit-exact — open.

---

## 7. Verdict

CF, ABI, vtbl membership, profile lower_bound, binary combat branch, skill sets, aim, and pursue linkage sealed. Naming is structural (`_Inferred`). Product English residual → **accept-with-gaps**.
