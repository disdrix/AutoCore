# Review B (skeptical / adversarial): `aa_00522060` Character_CountType1aCraftableBatches

| Field | Value |
|---|---|
| **Stable ID** | `aa_00522060` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY MEGA-002) |
| **Counterpart** | `reviews/A_aa_00522060_Character_CountType1aCraftableBatches.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | `Inv_Client_ValidateCraftAffordability` itself | **Falsified** — that name is a different unit; this is a character batch counter with 5 call sites including craft consume `005316c0` |
| 2 | Single inventory grid only | **Falsified** — every count is cargo `*( *(this+0x250)+0x2b0 )` **plus** locker `*(this+0xcbc)` |
| 3 | `__cdecl` / no stack cleanup / `RET` plain | **Falsified** — epilogue **`RET 0x10`** (`C2 10 00`) + ECX this |
| 4 | Available batches = `min(primary, secondary)` | **Falsified** — assembly **`ADD`**s primary floor-div and secondary min into `*out` |
| 5 | Type-agnostic item helper | **Falsified** — hard `CMP [obj+0x38], 0x1a` / else false |
| 6 | `FUN_005711c0` is free function (no this) | **Falsified** — thiscall on inventory grid; decompiler hides ECX |
| 7 | `FUN_00599dd0` is zero-arg global | **Falsified** — `MOV ECX,EDI` (blob) before CALL |
| 8 | Mode 1 skips secondary / mode 2 skips primary | **Falsified** — inverted: mode **1** skips primary; mode **2** skips secondary (`SETNZ` transform) |
| 9 | Simple path uses primary CBID `+0x4d0` | **Falsified** — simple path uses **`+0x4c0`** |
| 10 | Runtime Confirmed | **Fails** — open (no Launcher) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall + RET 0x10 + 4 stack args | **Confirmed** | Stack imbalance in ports |
| Type `0x1a` gate | **Confirmed** | Wrong recipe class |
| Dual cargo+locker counts | **Confirmed** | Under-count materials |
| Mode matrix 0/1/2 | **Confirmed** | Wrong bank skipped |
| Primary floor-div + secondary min ADD | **Confirmed** | Wrong affordability ceiling |
| Simple path `+0x4c0` | **Confirmed** | Wrong CBID |
| Product field English (primary/secondary/simple) | **Inferred** | Doc naming only |
| "CraftableBatches" product word | **High** (parent craft) | Misleading if type-1a is non-craft in some contexts |
| Runtime / bit-exact | **Open** | Silent drift |

---

## 3. Cross-check against raw / bytes

```text
raw 2026-07-23 ≡ live decompile 2026-08-05 ≡ clean Character_CountType1aCraftableBatches.cpp
(with dual-grid this restored from assembly)

00522066  MOV EBP, ECX              ; this = character
00522068  MOV dword ptr [EBX], 0    ; *out = 0
0052209b  CMP dword ptr [EAX+0x38], 0x1a
005220b2  RET 0x10                  ; and all other exits
005220b9  CMP AL, 2 / SETNZ         ; modeNot2
00522139  CDQ / IDIV ECX            ; primary batches
005221ed  ADD dword ptr [EAX], ECX  ; add secondary min
005221f8  SETG AL                   ; return *out > 0

Callees: 005711c0 InventoryGrid_CountItemsByCbid; 00599dd0 slot-count
Callers: 005316c0 craft; 0089bc30 / 0089bf50 / 0089c330 UI; xref 0089cc96
```

Reject ports that:

- Name this as ValidateCraftAffordability itself or a pure UI string helper.
- Count only one inventory.
- Take `min(primary, secondary)` instead of **ADD**.
- Invert mode 1/2 skip polarity.
- Use cdecl without popping 16 bytes.
- Drop the type-`0x1a` gate.

---

## 4. Surviving contract for AutoCore

```csharp
// Retail: character counts affordable type-0x1a craft batches from cargo+locker.
// Port: pure function over two inventory views + recipe blob offsets.

bool Character_CountType1aCraftableBatches(
    Character self,
    ItemObject obj,
    out int outBatches,
    byte mode,        // 0 both, 1 skip primary, 2 skip secondary
    byte simpleFlag)  // !=0 → only sum CBID at blob+0x4c0
{
    outBatches = 0;
    // guards: cargo, locker, type==0x1a, blob non-null
    // simple / primary floor-div / secondary min ADD — see clean source
    return outBatches > 0;
}

// Parent craft (0x005316c0):
//   if (!Count(..., mode, 0)) return soft-success;
//   if (requested > outBatches) return fail;
//   else remove materials and grant product.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/mode/dual-grid. Residual product-field English + runtime → **accept-with-gaps**.
