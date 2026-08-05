# Review A (reconstruction fidelity): `aa_008e9290` UiTargetPanel_PaintSlotChrome_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008e9290` |
| **VA** | `0x008e9290`–`0x008e931b` |
| **Canonical name** | `UiTargetPanel_PaintSlotChrome_Inferred` |
| **Ghidra name** | `FUN_008e9290` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_008e9290_UiTargetPanel_PaintSlotChrome_Inferred.md` |
| **System** | `interaction-activation` / client select-target 4-slot panel |
| **Verdict** | **accept-with-gaps** — 4-slot walk, EBX selected index, color dwords, vtbl paint sealed |
| **Dual status** | **Present (first full dual)** |

---

## 1. Purpose

Paint chrome for **four slot widgets** on the target panel after slot match (`UiTargetPanel_MatchSlotAndRefresh_Inferred` @ `0x008e9690` always calls this).

**ABI:**

| Slot | Role |
|------|------|
| **EAX** | panel* |
| **EBX** | selected slot index `0..3`, or **−1** (no match) from parent |

For each `i in 0..3` over `*(panel + 0x5d8 + 4*i)`:

1. Skip null slot pointers.
2. `colorBuf = slot->vtbl[+0x164](0)`.
3. Desired second-byte key: **`0xFF` (−1)** if `EBX == i`, else **`0xAF` (−0x51)**.
4. If `colorBuf[1] != key`, rebuild color dword, write via second `+0x164(0)`, `slot->vtbl[+0x34c]()`, then `obj = slot->vtbl[+0x1a0]()` and **`*(obj+0x184) = 0`**.

---

## 2. Color dwords (assembly-sealed)

Built on stack at `[esp+8]` (LE bytes `[8],[9],[a],[b]`):

| Case | Bytes LE | Dword | Compare key (`CL` / `[buf+1]`) |
|---|---|---|---|
| Selected (`EBX==i`) | `32 FF 32 FF` | **`0xFF32FF32`** | `0xFF` (−1) |
| Unselected | `AF AF AF FF` | **`0xFFAFAFAF`** | `0xAF` (−0x51) |

Decompiler `*puVar2 = unaff_ESI` is **wrong** — write source is the stack color dword, not ESI.

---

## 3. Inspected artifacts

| Artifact | Source |
|---|---|
| Raw/annotated/clean | `aa_008e9290_*` |
| Live decompile | Ghidra `0x008e9290` ≡ raw CF (4-slot loop) |
| Assembly | full body — color packing authoritative |
| Parent dual | `A_aa_008e9690_UiTargetPanel_MatchSlotAndRefresh_Inferred.md` |
| Callers | `FUN_008e9690` @ `0x008e9703`; xref `0x008eb467` |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| `ESI = EAX+0x5d8`, `EDI` loop 0..3 | **Yes** |
| Null slot skip | **Yes** |
| EBX select vs unselect key | **Yes** |
| Idempotent skip if `[buf+1]==key` | **Yes** |
| Write color + `+0x34c` + clear `+0x184` | **Yes** |
| No network | **Yes** |

---

## 5. Confidence

| Claim | Confidence |
|---|---|
| Panel in EAX; 4 slots at `+0x5d8` | **Confirmed** |
| EBX = selected index / −1 | **High** (parent dual) |
| Colors `0xFF32FF32` / `0xFFAFAFAF` | **Confirmed** (bytes) |
| Keys −1 / −0x51 | **Confirmed** |
| Product slot English | **Open** |
| Meaning of `+0x184` clear | **Open** (selection residual flag) |

---

## 6. Gaps

1. Product panel/slot names.
2. Full RGBA product meaning of `0x32`/`0xAF` channels.
3. Second xref site `0x008eb467` context.
4. Runtime capture of painted colors.

**Verdict:** **accept-with-gaps**.
