# Review A (reconstruction fidelity): `aa_008800e0` UI_VehicleInvSheet_RefreshHardpointWidgets_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008800e0` |
| **VA** | `0x008800e0` |
| **Canonical name** | `UI_VehicleInvSheet_RefreshHardpointWidgets_Inferred` |
| **Prior names** | `FUN_008800e0`, long Named_CalleeOf_* scaffold |
| **Review date** | `2026-07-29` (dual A/B — OWN-ONLY) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_008800e0_UI_VehicleInvSheet_RefreshHardpointWidgets_Inferred.md` |
| **System** | `inventory-transfer` (vehicle equip UI) |
| **Dual status** | **Present** (first dual pair) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Refresh **hardpoint / kit slot widgets** on the **vehicle inventory sheet** UI when:

1. Global local-player / world pointer `DAT_00d1b6d8` is non-null, and  
2. The sheet widget (`ESI`) reports open/visible via `vtbl+0x3d8` → non-zero.

For each non-null slot widget pointer on the sheet, call `FUN_00862b70` (slot enable/mode recompute vs selected vehicle `DAT_00d1b6d8+0xcd0`), then `FUN_0087d810(sheet)` for full stats/label rebuild.

```
if DAT_00d1b6d8 == 0: return
if sheet.vtbl+0x3d8() == 0: return
edi = *(DAT_00d1b6d8 + 0xcd0)   // selected vehicle (or null)
for each slot widget in { +0x5a0, +0x5a8, +0x5a4, +0x588..+0x59c, +0x5ac }:
  if non-null: FUN_00862b70(widget in EAX, vehicle in EDI)
FUN_0087d810(sheet)  // push esi; call
```

---

## 2. Calling convention — **SEALED**

| Slot | Role | Evidence |
|------|------|----------|
| **ESI** | vehicle inventory sheet UI* | Body `mov eax,[esi]; mov ecx,esi; call [eax+0x3d8]`; no prologue load of ESI |
| stack | none | no `ret N` — plain `ret` after callee |
| Callers set ESI | `FUN_008801b0` tail: `mov esi, ebp` then call; `FUN_00931d60`: `mov esi, [edi+0x1078]` |

Decompiler `void FUN_008800e0(void)` + `unaff_ESI` is correct for **custom register this** (common in this UI codebase).

---

## 3. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_008800e0_*`, `reconstructed-exact/FUN_008800e0.cpp` |
| Function record | `functions/aa_008800e0_FUN_008800e0.md` |
| Live decompile | Ghidra `0x008800e0` (2026-07-29) |
| Live bytes | `read_memory` length 200 — global gate, vtbl+0x3d8, slot offsets, `push esi; call FUN_0087d810` |
| Callers | `FUN_008801b0` @ `0x008810c5`, `FUN_00931d60` @ `0x00931d82` |
| Callee | `FUN_00862b70` (widget mode 0/1/2 + optional `vtbl+0x3b4/+0x34c`), `FUN_0087d810` (heavy sheet text/DPS rebuild) |
| Parent chain | Grab apply success → `FUN_00931d60` → this; vehicle sheet refresh `FUN_008801b0` → this |

**Not performed:** `disassemble_bytes`, Launcher, runtime, bit-exact.

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Gate `DAT_00d1b6d8 != 0` | **Yes** — `cmp dword [0x00d1b6d8],0` / jz exit |
| `sheet.vtbl+0x3d8()` bool | **Yes** — `call [eax+0x3d8]; test al,al` |
| Load `EDI = *(DAT_00d1b6d8+0xcd0)` once before slot loop | **Yes** — `mov edi,[ecx+0xcd0]` |
| Ten non-null widget checks | **Yes** — offsets below |
| Each non-null → `FUN_00862b70` | **Yes** — EAX=widget from load; EDI=vehicle |
| Tail `FUN_0087d810(sheet)` | **Yes** — `push esi; call` |
| Clean missing ESI param | **Weak** — CF matches; signature should document ESI |

### 4.1 Slot widget offsets (byte; `ESI+n`)

| Offset | Index form (`ESI[i]`) | Order in body |
|-------:|----------------------|---------------|
| `+0x5a0` | `[0x168]` | 1st |
| `+0x5a8` | `[0x16a]` | 2nd |
| `+0x5a4` | `[0x169]` | 3rd |
| `+0x588` | `[0x162]` | 4th |
| `+0x58c` | `[0x163]` | 5th |
| `+0x590` | `[0x164]` | 6th |
| `+0x594` | `[0x165]` | 7th |
| `+0x598` | `[0x166]` | 8th |
| `+0x59c` | `[0x167]` | 9th |
| `+0x5ac` | `[0x16b]` | 10th |

Order is **not** ascending — decompiler list matches live load order (0x5a0, 0x5a8, 0x5a4, then 0x588…).

`FUN_00862b70` (callee seal): if no vehicle (`EDI==0`) sets widget mode field `+0x520` (`[0x148]`) to 0; else compatibility probe → mode 1 or 2; on mode change calls `vtbl+0x3b4` + `vtbl+0x34c`.

---

## 5. Globals

| Symbol | Role |
|--------|------|
| `DAT_00d1b6d8` | local player / character host used across inventory UI |
| `DAT_00d1b6d8+0xcd0` | currently selected vehicle for sheet (null = empty selection) |

---

## 6. Naming

| Claim | Confidence |
|---|---|
| Role = vehicle sheet hardpoint widget refresh | **High** (callers + 00862b70 + 0087d810) |
| `UI_VehicleInvSheet_RefreshHardpointWidgets_Inferred` | **Probable** |
| Sheet is `client+0x1078` | **High** at call sites (not body) |
| Product window class name | **Open** |

---

## 7. Gaps

- Product names for each slot widget (front/turret/kit/…).
- Full `FUN_0087d810` dual not this unit (heavy; leave residual).
- Whether all ten slots are always allocated on sheet construct.

---

## 8. Verdict

**accept-with-gaps** — ESI this, global gates, ten slot offsets, and two callees sealed. Name remains `_Inferred`.
