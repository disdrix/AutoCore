# Review A (reconstruction fidelity): `aa_0055e1e0` SoftCastHitList_ControllerFillWrapper_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0055e1e0` |
| **VA** | `0x0055e1e0`–`0x0055e21f` inclusive (**64 B** / `0x40`) |
| **Canonical name** | `SoftCastHitList_ControllerFillWrapper_Inferred` |
| **Ghidra name** | `FUN_0055e1e0` |
| **Prior scaffold** | `FUN_0055e1e0` (2026-07-23 trio) |
| **Rejected misname** | free 2-arg cdecl; "core fill" merge with `006ca890`; product class without `_Inferred` |
| **Review date** | `2026-08-05` (R11-003 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_0055e1e0_SoftCastHitList_ControllerFillWrapper_Inferred.md` |
| **System** | interaction-activation (soft-cast hit list) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + `get_function_callers` / `get_function_xrefs` + `get_assembly_context` (hub). **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Soft-cast hit-list **controller fill wrapper**:

```text
SoftCastHitList_ControllerFillWrapper_Inferred(controller, soft_desc, hit_list_backref)
  align stack 16; allocate 0x50 local frame
  local_entry.vtbl = 0x009D27A8
  local_entry[+0x44] = 0
  SoftCastHitList_CoreFillAndRegister_Inferred(
      &local_entry,                 // ECX
      *(controller + 0xC4),         // manager
      soft_desc,
      *(controller + 0xD0),         // related (nullable)
      0,                            // payload hard 0
      hit_list_backref)
  RET 0x8
```

Sole retail caller: dualed **`Client_InteractWorldClickHub`** (`0x00925820`) @ `0x00925c32` — after hit-list ctor (`0x0040c410`) and before sort gate (`0x0048a060`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ R11-003 append) | `docs/reconstruction/raw/aa_0055e1e0_FUN_0055e1e0.md` |
| Annotated | `docs/reconstruction/raw/aa_0055e1e0_FUN_0055e1e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/SoftCastHitList_ControllerFillWrapper_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0055e1e0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0055e1e0_FUN_0055e1e0.md` |
| Named record | `docs/reconstruction/functions/aa_0055e1e0_SoftCastHitList_ControllerFillWrapper_Inferred.md` |
| Live | decompile ≡ scaffold CF; body 64 B; `RET 0x8`; 1 CALL xref |
| Core dual | `SoftCastHitList_CoreFillAndRegister_Inferred` (`aa_006ca890`, MEGA-062) |
| Hub | `Client_InteractWorldClickHub` call @ `0x00925c32` → sort @ `0x00925c3e` |

---

## 3. Signature (sealed)

```c
// ECX = controller*; 2 stack args; void; RET 0x8
void __thiscall SoftCastHitList_ControllerFillWrapper_Inferred(
    void *controller,
    uint32_t *soft_desc,
    uint32_t hit_list_backref);
```

| Slot | Source | Conf |
|---|---|---|
| this | **ECX** controller (`MOV EDX,[ECX+0xD0]` then `MOV ECX,[ECX+0xC4]`) | **Confirmed** |
| soft_desc | **`[EBP+0x08]`** → core stack soft_desc | **Confirmed** |
| hit_list_backref | **`[EBP+0x0C]`** → core stack backref | **Confirmed** |
| local entry this | **`LEA ECX,[ESP+0x14]`** after 5 pushes (= frame base) | **Confirmed** |
| vtbl install | **`MOV [ESP+0x14],0x009D27A8`** | **Confirmed** |
| payload | **`PUSH 0`** hard | **Confirmed** |
| cleanup | **`RET 0x8`** (`C2 08 00`) | **Confirmed** |
| return | void; no EAX contract | **Confirmed** |

**Note:** Decompiler shows free 5-arg call of core with controller as first decompiler param; assembly seals **local entry as core this** + controller field loads only.

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| Frame align `AND ESP,~0xF` / `SUB ESP,0x50` | **Yes** | **Confirmed** |
| Load related `controller+0xD0`, manager `+0xC4` | **Yes** | **Confirmed** |
| Push order: backref, 0, related, soft_desc, manager | **Yes** | **Confirmed** |
| Install vtbl + pre-zero `+0x44` | **Yes** | **Confirmed** |
| `CALL 0x006ca890` with ECX=local entry | **Yes** | **Confirmed** |
| `MOV ESP,EBP` / `POP EBP` / `RET 0x8` | **Yes** | **Confirmed** |
| Body size 64 B / terminal before `0x0055e220` | **Yes** | **Confirmed** |

---

## 5. Naming gate

| Rule | Result |
|---|---|
| Evidence-only English | **Pass** — role is structural wrapper under dualed soft-cast hub path |
| `_Inferred` required | **Pass** — no PDB/string for product method name |
| No invent product class | **Pass** — controller / entry types opaque |
| Family prefix | **Pass** — matches `SoftCastHitList_*` dualed siblings |

---

## 6. Gaps (do not block dual seal)

- Product English for controller class and fields `+0xC4` / `+0xD0`.
- Full vtbl `0x009D27A8` method map.
- Runtime / bit-exact / differential (Terminal **false**).

---

## 7. Verdict

**accept-with-gaps** — CF/ABI/RET0x8/local-entry/vtbl/sole-hub-caller sealed; product English + runtime open.
