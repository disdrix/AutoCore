# Review A (reconstruction fidelity): `aa_0088ef70` UI_InvSheet_ApplySelectionTint_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0088ef70` |
| **VA** | `0x0088ef70` |
| **Canonical name** | `UI_InvSheet_ApplySelectionTint_Inferred` |
| **Prior names** | `FUN_0088ef70`, `Named_CalleeOf_Client_RefreshOpenMissionUiWindows_0088ef70` |
| **Review date** | `2026-07-29` (dual A/B — OWN-ONLY) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_0088ef70_UI_InvSheet_ApplySelectionTint_Inferred.md` |
| **System** | `inventory-transfer` (inventory sheet UI) |
| **Dual status** | **Present** (first dual pair) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Apply a **color tint** to up to two child widgets on an inventory-related sheet (`ESI`), then force a redraw:

```
color = DAT_00afdf0c                    // default 0xFFFFFFFF (white/opaque)
if DAT_00d1b6d8 != 0 && *(DAT_00d1b6d8 + 0xcd0) == 0:
  color = 0xFF414141                    // dim grey when no vehicle selected
for widget in { sheet+0x5b4, sheet+0x5b8 }:
  if non-null:
    widget.vtbl+0x15c(0, &color)        // set color (arg0=0, arg1=&ARGB)
    widget.vtbl+0x34c()                 // refresh/draw
```

Used after grab/unequip/mission UI refresh when the **storage/garage sheet** (`client+0x105c`) is open (`FUN_00931d60`), and from `Client_RefreshOpenMissionUiWindows` / sheet-local paths with **ESI** preset.

---

## 2. Calling convention — **SEALED**

| Slot | Role | Evidence |
|------|------|----------|
| **ESI** | inventory sheet UI* | Body `cmp [esi+0x5b4]`; callers `mov esi, [edi+0x105c]` or `mov esi, ebp` |
| stack | none | epilogue `pop ecx` (local) + `ret` |
| Local | 4-byte ARGB on stack | prologue `push eax` / `sub`-less single-slot frame |

Decompiler `unaff_ESI` matches register this pattern (sibling of `0x008800e0`).

---

## 3. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_0088ef70_*`, `reconstructed-exact/FUN_0088ef70.cpp` |
| Function record | `functions/aa_0088ef70_FUN_0088ef70.md` |
| Live decompile | Ghidra `0x0088ef70` (2026-07-29) |
| Live bytes | `read_memory` length 180 — color load, grey override, two widgets, `pop ecx; ret` |
| `DAT_00afdf0c` | `read_memory` → `ff ff ff ff` (**0xFFFFFFFF**) |
| Callers | `Client_RefreshOpenMissionUiWindows` (`0x0093ab02`), `FUN_00931d60` (`0x00931da8`), `FUN_0088f8e0` (`0x008902e8`) |
| Sibling | `aa_008800e0` vehicle sheet hardpoint refresh (same `+0xcd0` vehicle selection gate) |

**Not performed:** `disassemble_bytes`, Launcher, runtime, bit-exact.

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| `local = DAT_00afdf0c` | **Yes** — `mov eax,[0x00afdf0c]; mov [esp],eax` |
| If char host and `+0xcd0==0` → `0xFF414141` | **Yes** — stores `0x41` to RGB bytes, `0xFF` alpha |
| Widget `+0x5b4` non-null → `vtbl+0x15c(0,&color)` + `vtbl+0x34c` | **Yes** — `push &local; push 0; call [edx+0x15c]` |
| Widget `+0x5b8` same | **Yes** |
| No third widget | **Yes** — ends after pair |
| Clean ≡ raw CF | **Yes** |

### 4.1 Color seal

| Value | Meaning (inferred) | Evidence |
|-------|--------------------|----------|
| `0xFFFFFFFF` | default tint (white) | DAT bytes + load |
| `0xFF414141` | disabled / no-vehicle grey | immediate when `+0xcd0==0` |

Gate requires **both** `DAT_00d1b6d8 != 0` **and** selected vehicle pointer null — if no char host, keep default white (do not grey).

---

## 5. Offsets / vtbl

| Offset | Role |
|--------|------|
| sheet `+0x5b4` | widget A (color target) |
| sheet `+0x5b8` | widget B |
| widget vtbl `+0x15c` | set color (thiscall; args `0`, `uint32_t*`) |
| widget vtbl `+0x34c` | refresh |
| char host `+0xcd0` | selected vehicle (shared with vehicle sheet unit) |

---

## 6. Naming

| Claim | Confidence |
|---|---|
| Role = selection-dependent tint on two sheet widgets | **High** |
| `UI_InvSheet_ApplySelectionTint_Inferred` | **Probable** |
| Host sheet often `client+0x105c` | **High** at primary refresh chain |
| Widget English labels | **Open** |

---

## 7. Gaps

- Product names for widgets at `+0x5b4/+0x5b8`.
- Whether grey is “no vehicle” only or also used for other empty selection semantics.
- Exact ARGB channel order assumption (stored as LE `41 41 41 FF` on stack) — value sealed as dword `0xFF414141`.

---

## 8. Verdict

**accept-with-gaps** — ESI this, color constants, dual-widget CF sealed from live memory. Leave product widget names open.
