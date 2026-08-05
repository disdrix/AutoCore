# Review A (reconstruction fidelity): `aa_00811e00` Client_ProcessSectorUpdate_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00811e00` |
| **VA** | `0x00811e00`–`0x008120c8` |
| **Canonical name** | `Client_ProcessSectorUpdate_Inferred` |
| **Ghidra name** | `FUN_00811e00` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W26-M) |
| **Counterpart** | `reviews/B_aa_00811e00_Client_ProcessSectorUpdate_Inferred.md` |
| **System** | client net / sector object update |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `analyze_function_complete`; callers |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Client **ProcessSectorUpdate** for an **already-present** world object:

1. Debug-trace `"Requesting ProcessSectorUpdate\n"`.
2. If `packet+0xA1 ≠ 0`: special apply (`vtbl+0xC4`, `FUN_009972a0`, `FUN_008024d0`) and return.
3. If object matches mission bind at `game+0xE98` → return (no-op).
4. If identity pair incomplete (`(pkt+8 & pkt+0xC) ≠ 0xFFFFFFFF`) → `vtbl+0x260` and return.
5. Merge `packet+0xA8` into object flag bit2 at `+0x17C`; optional `FUN_0092a200` mark.
6. Get physics via `vtbl+0x1CC`; copy transform from packet `+0x64..`; set phys bit; apply via `FUN_004e87d0` / `FUN_004e88e0` + phys vtbls.

Create path is sibling `FUN_008120d0` (not OWN).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00811e00_FUN_00811e00.md` (+ 2026-07-29 W26-M append) |
| Annotated | `docs/reconstruction/raw/aa_00811e00_FUN_00811e00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_ProcessSectorUpdate_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00811e00.cpp` |
| Function | `docs/reconstruction/functions/aa_00811e00_FUN_00811e00.md` |
| Named | `docs/reconstruction/functions/aa_00811e00_Client_ProcessSectorUpdate_Inferred.md` |
| Live | decompile ≡ raw; `read_memory` body/epilogue; string @ `0x00a7f17c` |
| Callers | 7 recv/update handlers including `FUN_00814400` (0x201C dual) |

---

## 3. Signature (sealed)

```c
// Multi-reg:
//   ECX = packet body*
//   EAX = world object*
//   Stack[0x4] = game/client*
//   RET 4; void
void Client_ProcessSectorUpdate_Inferred(void* packet, void* game);
```

| Formal | Source | Conf |
|---|---|---|
| packet | ECX → ESI | **High** |
| object | EAX → EDI (`in_EAX`) | **High** |
| game | Stack[0x4] → EBX | **High** |
| cleanup | `C2 04 00` | **High** |

Prologue proof (`read_memory`):
`55 8B EC 83 E4 F0 83 EC 34 53 8B 5D 08 56 57 68 7C F1 A7 00 8B F8 8B F1 FF 15 …`

---

## 4. Control flow (clean ≡ raw ≡ live)

| Stage | Match | Conf |
|---|---|---|
| OutputDebugStringA ProcessSectorUpdate | **Yes** | **High** |
| `+0xA1` early special path | **Yes** | **High** |
| `game+0xE98` bind skip | **Yes** | **High** |
| Partial identity → `vtbl+0x260` | **Yes** | **High** |
| Flag merge `+0xA8` → obj `+0x17C` bit2 | **Yes** | **High** |
| `FUN_0092a200` filter mark | **Yes** | **High** |
| Physics via `vtbl+0x1CC` + transform copy | **Yes** | **High** |
| Nested `004e87d0`/`004e88e0` full CF | Out of OWN | **Medium** |
| Body 713 B exclusive end before create sibling | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

- Body: **713 B** (`0x00811e00`–`0x008120c8`); pad `CC` then `FUN_008120d0` @ `0x008120d0`.
- Epilogue @ `0x008120c0`: `5F 5E 5B 8B E5 5D C2 04 00`.
- String @ `0x00a7f17c`: `Requesting ProcessSectorUpdate\n`.

---

## 6. Gaps

- Product English for the multi-opcode caller family (this VA is shared update worker, not one opcode).
- Full nested physics/math helpers (`FUN_004e87d0`, `FUN_004e88e0`, `FUN_008024d0`, `FUN_009972a0`) — not OWN.
- Exact meaning of phys adjusted `+0x188` bit0 beyond flag plumbing.
- Runtime / differential — open.

---

## 7. Verdict

CF, multi-reg ABI, string-backed ProcessSectorUpdate role, packet/object offset map for **this** unit, and exclusive body bounds are sealed. Nested helper interiors and product wire names remain gaps → **accept-with-gaps**.
