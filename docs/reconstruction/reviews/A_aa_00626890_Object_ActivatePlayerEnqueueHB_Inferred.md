# Review A (reconstruction fidelity): `aa_00626890` Object_ActivatePlayerEnqueueHB_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00626890` |
| **VA** | `0x00626890`–`0x00626a46` (438 B / `0x1B6`) |
| **Canonical name** | `Object_ActivatePlayerEnqueueHB_Inferred` (structural; product/PDB open) |
| **Ghidra name** | `FUN_00626890` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual W27-F) |
| **Counterpart** | `reviews/B_aa_00626890_Object_ActivatePlayerEnqueueHB_Inferred.md` |
| **System** | object / player bind / CVOGHB activate |
| **Verdict** | **accept-with-gaps** — CF + ABI + TFID/HB chain sealed; product class + nested helper English open |
| **Dual status** | **Present (first full dual)** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` + callers/callees/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

**Vtable activate** on a host object:

- Optional related entity from `host+0x18` (vfunc `+0x214`) → `Object_SetPhysBodyTypeIfNotReady`.
- Local player via `FUN_00578270` + vfunc `+0x210(0)`.
- **Sole** dualed caller of `Object_SetTFID_ApplyPhysMode_Rebind` (`FUN_004c4880` @ `0x0062690d`).
- Selection + flag writes; `operator_new(0x2c)` + `FUN_006264e0` → enqueue + `CVOGHBBase_Start` when owner bound; store at `host+0x6c4`.
- Always `FUN_00578b30` fire-tail.

Evidence: W26-F dual of `FUN_004c4880` documents this sole caller; DATA vtable `@0x009d1ba8`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live decompile | full body @ `0x00626890` |
| Bounds | `get_function_by_address` → `00626890`–`00626a46` |
| Entry/exit bytes | `read_memory` @ `0x00626890`, `0x00626a30` |
| Vtable | `read_memory` @ `0x009d1ba0` (slot `0x00626890`) |
| Peer dual | `Object_SetTFID_ApplyPhysMode_Rebind` (W26-F) |
| Raw / annotated / clean | W27-F updated |

**Not performed:** Launcher, runtime golden, dual of `FUN_006264e0` / `FUN_00578270` / `FUN_0051f890`.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body range `00626890`–`00626a46` (438 B) | **Confirmed** | `get_function_by_address` |
| thiscall host ECX + SEH + plain RET | **Confirmed** | entry `mov ebp,ecx`; exit `C3` |
| Vtable-only dispatch | **Confirmed** | DATA `@0x009d1ba8`; 0 callers |
| TFID rebind sole-caller site | **Confirmed** | W26-F + call `@0x0062690d` |
| HB new(0x2c) / enqueue / Start | **Confirmed** | named callees |
| Always `FUN_00578b30` | **Confirmed** | fallthrough |
| Surface `__fastcall` label | **Residual** | decompiler; machine thiscall |
| `unaff_ESI` third select arg | **Open** | decompiler residual |
| Product class / method name | **Inferred** | `_Inferred` |
| Runtime / differential | **Open** | |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| SEH frame | Yes |
| Related resolve / phys-type | Yes |
| Player resolve gate | Yes |
| TFID rebind | Yes |
| `FUN_0051f890(1)` | Yes |
| Host float → player flags | Yes |
| Phys-sub `@+0x250` branch | Yes |
| SetSelectedTarget + `+0xd78` | Yes |
| new / ctor / enqueue / Start | Yes |
| `+0x6bb=0` | Yes |
| Always fire-tail | Yes |
| Plain RET | Yes |

---

## 5. Callers

| Caller | Site | Notes |
|---|---|---|
| *(none code)* | DATA `@ 0x009d1ba8` | vtable method |

---

## 6. Gaps

1. Retail / PDB symbol and owning class.
2. Product English of host floats `+0x184/+0x188` and player flags.
3. Full dual of `FUN_006264e0` / `FUN_0051f890` / `FUN_00578270`.
4. `unaff_ESI` residual; null-`pAction` surface hazard.
5. Runtime golden for activate path.

**Verdict:** **accept-with-gaps** — sealed outer activate CF, ABI, TFID sole-caller, and HB enqueue chain; product class + nested English residual.
