# Dual A/B report — W19-H OWN `0x00513e30` + `0x00513580`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W19-H  
**Scope:** VAs `0x00513e30`, `0x00513580` only.  
**Excluded:** Launcher; parent ledger edits (WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER).  
**Ghidra:** `decompile_function` + `read_memory` only (no `disassemble_bytes`).  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdicts

| Unit | Canonical | Verdict |
|------|-----------|---------|
| `aa_00513e30` | `Item_SetCustomized` | **accept-with-gaps** — mask **`0x100000` / bit 20 sealed** |
| `aa_00513580` | `Item_SumEquippedComponentValues` | **accept-with-gaps** — sum **`component+0x94`** + six-type switch sealed |

---

## VA `0x00513e30` — Item_SetCustomized

### Sealed facts

1. **Mask `0x100000`** = **bit 20** of flags dword at **`item+0x17c`** (`object[0x5f]`).  
   Bytes: `81 e6 00 00 10 00`. Shifts: `0x14`.
2. **Role:** dedicated **Customized** flag setter (sibling of Broken `0x00513de0`).  
   Peer: trade string *“customized to you”*; permanent-customize Yes `FUN_00513e30(1)`.
3. **ABI:** `__thiscall` — **ECX** = item; one stack arg (low byte); **`ret 4`**.  
   Body: `0x00513e30` … `0x00513e63`.
4. **XOR set-to-value:**  
   `flags ^= (((desired & 0xff) << 20) ^ flags) & 0x100000`
5. **Dirty-on-change only:** if bit differs → **`FUN_00512670`** (`| 0x20000` + chain).
6. **No vtbl tail** (contrast Broken’s `jmp [vtbl+0x90]`).
7. **Live decompile ≡ 2026-07-23 raw** (append-only live section recorded).

### Gaps

- Original PDB symbol.  
- Exhaustive caller census (xrefs: `00810360`, `005cb520`, `005cbcb0`, `0091260e`, `009126a9`).  
- Non-0/1 desired edge cases.  
- Runtime / bit-exact / image diff.

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00513e30_Item_SetCustomized.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00513e30_Item_SetCustomized.md` |
| Function record | `docs/reconstruction/functions/aa_00513e30_FUN_00513e30.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Item_SetCustomized.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00513e30.cpp` |
| Raw (authoritative + live) | `docs/reconstruction/raw/aa_00513e30_FUN_00513e30.md` |
| Annotated | `docs/reconstruction/raw/aa_00513e30_FUN_00513e30.annotated.md` |

---

## VA `0x00513580` — Item_SumEquippedComponentValues

### Sealed facts

1. **Purpose:** sum **`*(int32*)(component + 0x94)`** over host item equipped slots.  
   Bytes: `03 98 94 00 00 00`.
2. **Gate:** `FUN_004ce940()` catalog singleton; null → **0**.
3. **Loop:** `i = 0 .. vtbl[+0x60)`; slot id = `vtbl[+0x5c](i)`.
4. **Type switch** on host `clonebase+0x38` (`item[0x2a]+0x38`):  
   **10 → `FUN_00508b60`**, **0xc → `508ac0`**, **0xe → `508bb0`**,  
   **0x1c → `508b10`**, **0x44 → `508c50`**, **0x46 → `508c00`**; else skip.  
   Jump table @ `0x00513714` + case map @ `0x00513730`.
5. **ABI:** thiscall ECX=item; plain `ret`; EAX=sum. Body `0x00513580`–`0x00513712`.
6. **Callers:** `0x005142a0` store sell price; `0x00514250` related price helper.
7. **Live decompile ≡ 2026-07-23 raw**.

### Gaps

- Product English for `+0x94` and type enums.  
- Empty-slot id convention (`-1` miss in lookup).  
- Original PDB; runtime golden sums.

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00513580_Item_SumEquippedComponentValues.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00513580_Item_SumEquippedComponentValues.md` |
| Function record | `docs/reconstruction/functions/aa_00513580_FUN_00513580.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Item_SumEquippedComponentValues.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00513580.cpp` |
| Raw (authoritative + live) | `docs/reconstruction/raw/aa_00513580_FUN_00513580.md` |
| Annotated | `docs/reconstruction/raw/aa_00513580_FUN_00513580.annotated.md` |

---

## Absolute roots

`C:\Users\josh\Documents\GitHub\AutoCore\` + paths above.

This report: `docs/agents/task-dual-ab-00513e30-00513580-w19h-report.md`

---

## AutoCore impact

- **Customized bit20:** client/server item models should treat **`flags & 0x100000`** as customized-to-you; prefer a single **SetCustomized(bool)** XOR mutator; trade/equip paths must honor the bit. Dirty bit **`0x20000`** may need chain propagation when mirroring client.
- **Component sum:** vendor sell (`GetStoreSellPrice`) depends on **`SumEquippedComponentValues + item+0xC4`** before scale; server economy ports need the same `+0x94` addend over resolved components for matching types.

---

## Policy compliance

| Rule | Status |
|------|--------|
| OWN VAs only | Yes |
| decompile + read_memory only | Yes |
| No disassemble_bytes | Yes |
| No Launcher | Yes |
| No parent ledger edits | Yes |
| Dual A+B written | Yes |
| Trio raw/annotated/clean + function record | Yes |
