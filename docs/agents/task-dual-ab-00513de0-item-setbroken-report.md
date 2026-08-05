# Dual A/B report — `aa_00513de0` Item_SetBroken (mask **0x80000**)

**Date:** 2026-07-29  
**Scope:** OWN ONLY VA `0x00513de0`. Dual A/B + artifacts. Seal mask **`0x80000`**.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG.  
**Ghidra:** `decompile_function` + `read_memory` only.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00513de0` Item_SetBroken | **accept-with-gaps** — **mask `0x80000` / bit 19 sealed** |

---

## Sealed facts

1. **Mask `0x80000`** = **bit 19** of flags dword at **`item+0x17c`** (`object[0x5f]`).  
   Bytes: `81 e6 00 00 08 00` (`and esi, 0x80000`). Shifts: `0x13`.

2. **Role:** dedicated **`ItemFlag_Broken` setter** (not reader, not capacity, not stack eligibility).  
   Registry + peer duals (`"Broken: "`, overlay, CountItemsByCbid) already name the bit; this unit **owns the write**.

3. **ABI:** `__thiscall` — **ECX** = item; one stack arg = desired Broken (low byte via `movzx`); **`ret 4`**.  
   Boundary: `0x00513de0` … `0x00513e2c` (`c2 04 00` + `CC`).

4. **XOR set-to-value:**  
   `flags ^= (((desired & 0xff) << 19) ^ flags) & 0x80000`  
   → bit19 becomes **(desired & 1)**; other flags bits untouched.

5. **Dirty-on-change only:** if `((flags >> 19) & 1) != (desired & 0xff)` then **`FUN_00512670`**:  
   `item+0x17c |= 0x20000`, walk `+0xac` chain same OR.  
   (Dirty mask **`0x20000`** is **not** Broken.)

6. **Post-write side effect:** if Broken set (`test byte [ecx+0x17e], 8`), **tail-jmp** `[vtbl+0x90]` with stack arg forced **0** (not a returning `call`).

7. **Live decompile ≡ 2026-07-23 raw** (append-only live section recorded).

8. **Not this unit:** eligibility `0x00513e70`; capacity `0x0040abf0`; bit20 sibling setter `0x00513e30` (mask `0x100000`).

---

## Gaps

1. Product name / purpose of **vtable `+0x90`** (notify when Broken set).  
2. Complete **caller census** (samples only: `004d08c0`, `004d4440`, `0050ac80`, RE-failure path).  
3. Whether any caller passes desired **≠ {0,1}** (compare uses full low byte; write uses bit0 only).  
4. Original PDB symbol.  
5. Runtime capture / bit-exact / image diff.

---

## Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00513de0_Item_SetBroken.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00513de0_Item_SetBroken.md` |
| Function record | `docs/reconstruction/functions/aa_00513de0_FUN_00513de0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Item_SetBroken.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00513de0.cpp` |
| Raw (authoritative + live) | `docs/reconstruction/raw/aa_00513de0_FUN_00513de0.md` |
| Annotated | `docs/reconstruction/raw/aa_00513de0_FUN_00513de0.annotated.md` |
| This report | `docs/agents/task-dual-ab-00513de0-item-setbroken-report.md` |

Absolute roots: `C:\Users\josh\Documents\GitHub\AutoCore\` + paths above.

---

## AutoCore impact

- Client/server item models should treat **`flags & 0x80000`** as **Broken**.  
- Prefer a single **SetBroken(bool)** mutator (XOR bit set) rather than ad-hoc `|=` / `&= ~`.  
- When flipping Broken, peer dirty bit **`0x20000`** may need propagation if mirroring client dirty chain.  
- Clearing Broken must **not** invoke the “Broken set” notify path (client only tails when bit remains set).
