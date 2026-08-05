# Review B (skeptical / adversarial): `aa_00931870` Inventory_WriteSwapDebugLog

| Field | Value |
|---|---|
| **Stable ID** | `aa_00931870` |
| **VA** | `0x00931870` |
| **Canonical name** | `Inventory_WriteSwapDebugLog` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Adversarial dual (attack over-claims) |
| **Counterpart** | `reviews/A_aa_00931870_Inventory_WriteSwapDebugLog.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** on CF/strings/free; **reject** “gameplay swap”, “single list”, “cdecl/void-truncated body”, “network path” |

---

## 1. What this is *not*

| Attack | Result |
|---|---|
| “Performs inventory swap / move items” | **Falsified** — only fopen/fprintf/fclose + list destroy; no grid place/merge/send |
| “Network / packet helper” | **Falsified** — pure local file log |
| “One list dump then return” | **Falsified** — **two** walks; image frees **both** heads |
| “Decompiler body is complete through ret” | **Falsified** — Ghidra ends mid-free @ `0x009319f6`; real epilogue `ret 0x1c` @ `0x00931a44` |
| “`operator_delete` noreturn aborts function” | **Falsified** — free **loops** then second list; SEH restore; ret |
| “`__cdecl` / caller pops 0x1c” | **Falsified** — `C2 1C 00` stdcall |
| “Quantity is raw field `item+0x164`” | **Falsified** — `+0x160/+0x164` are **COID** halves (`%I64d`); qty is **vtbl+0x25c** |
| “Must run for cargo transfer correctness” | **Falsified** — debug log; production path works if fopen fails (caller continues) |
| “param_1/3/4/6 unused ⇒ junk signature” | **Partial** — unused as **scalars** because they are **list object padding/size**; still part of 12-byte values |
| Name implies only “swap” | **Weak** — strings say Swap; sole caller is swap-ish organizer — name **High** for log role, not for full feature English |

---

## 2. Decompiler hazards (attack surface)

| Decomp artifact | Reality |
|---|---|
| Truncation after first list `operator_delete` | Image: free listA nodes+head, zero slots, **same for listB (EDI)**, pop regs, `ADD ESP,0xC`, `ret 0x1c` |
| `void FUN_…` with completeness “check EAX” | No return value; ignore |
| SEH / `FUN_00404060` only on fail | Agree fail path clears listA; success path frees both without `00404060` (manual empty+delete) |
| `param_2` / `param_5` are full list objects | They are **head pointers** (`list+4`); object base is prior dword |
| Second loop “destroys EBX as listA head” | Under 5-arg fprintf window, `MOV EBX,[ESP+0x38]` **reloads listA head** — not a latent bug |

---

## 3. Layout / semantics challenges

| Challenge | Response | CF |
|---|---|---|
| Is COID really `%I64d` from two dwords? | Pushes lo then hi then qty; format `%I64d` then `%d` — **yes** (MSVC 64-bit from two 32-bit pushes) | High |
| Could `node+8` be non-item? | Null-checked; qty vtbl and COID offsets match inventory item duals | High item\* |
| List order A/B = cargo/locker? | **Caller-owned** — this unit is order-agnostic; do not seal grid roles here | Open (caller) |
| `wt+` vs `at` race | Documented open policy only; no flock | High as written |
| Empty list | Head next == head → skip walk; still free head | High |
| `isAfter` multi-value | Only byte `==0` vs else; any nonzero is After banner | High |

---

## 4. Surviving contract (minimal)

```c
// stdcall; args: List12 a, List12 b, char isAfter; ret 0x1c
// List12: { +0 base, +4 head*, +8 size }; node: {next, prev, item*}
void Inventory_WriteSwapDebugLog(List12 a, List12 b, char isAfter);

// Effects:
// 1) Append (else create) InventoryLog.txt
// 2) Banner Before (isAfter==0) or After (else)
// 3) For each non-null item in a then b:
//      fprintf coid(item+0x160 as u64) + qty(vtbl+0x25c)
// 4) fclose; destroy all nodes+heads of a and b (by-value temps consumed)
// Non-effects: no grid mutation, no packets, no gameplay rules
```

Do **not** treat as:

- swap implementation
- required production dependency
- complete decompiler free path without image tail

---

## 5. Cross-check vs dual A

| A claim | B stance |
|---|---|
| Name from strings | **Agree** High |
| `ret 0x1c` stdcall | **Agree** — image |
| Two list walks + dual free | **Agree** — attack any single-list summary |
| COID `+0x160/+0x164`, qty vtbl `+0x25c` | **Agree** |
| Decomp truncates free | **Agree** hazard table |
| Sole caller `FUN_00955010` @ two sites | **Agree** (xref list); do not dual caller here |
| Clean scaffold incomplete | **Agree** — dual is source of truth for free tail |
| Product English of organizer | **Agree** open |

---

## 6. Residual (honest)

1. Caller `FUN_00955010` full dual (list fill order, before/after flag provenance).
2. Live `InventoryLog.txt` sample lines.
3. Whether fail-path SEH also destroys listB (image fail path shown for listA; listB may be earlier SEH state — residual).
4. `list+0` / allocator field.
5. Ghidra function bounds should be extended to `0x00931a46` (tooling residual, not logic).

---

## 7. Verdict

### **accept-with-gaps**

A’s sealed CF, strings, stdcall width, item field use, and decompiler-tail correction hold under adversarial review. Reject any claim that this function **implements** inventory swap or is required for transfer correctness. Gaps are caller semantics, optional fail-path listB unwind detail, and runtime log capture.
