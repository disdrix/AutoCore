# Review B (skeptical / adversarial): `aa_00573ce0` IgnoreList_EraseEntriesByTfid_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00573ce0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` |
| **Counterpart** | `reviews/A_aa_00573ce0_IgnoreList_EraseEntriesByTfid_Inferred.md` |
| **Agent** | R13-040 OWN-ONLY dual (dual start **2686**) |
| **Verdict** | **accept-with-gaps** on CF/role; product host class + unused-arg semantics remain open |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Skill-cast / ability residual math (partition nest skills-abilities) | **Falsified as cast** — pure social list mutator; sole consumer is remove-from-ignore residual with English *"has been removed from your ignore list"* |
| 2 | Read-only find (same as parent `00573a90`) | **Falsified** — body calls `operator_delete` + `memmove` + mutates end pointer |
| 3 | Erase first match only | **Falsified** — after compact, cursor is **not** advanced; loop re-tests current slot → multi-match |
| 4 | Friends-list vector (+0x8) / friends erase | **Falsified** — vector **+0x38/+0x3c**; friends TFID find is `FUN_005739d0` at +0x8 |
| 5 | Same function as sibling `FUN_00573d50` | **Falsified** — that plate uses **+0x28/+0x2c** |
| 6 | Same ABI as find twin (`RET 0x8`, two stack args) | **Falsified** — this unit is **`RET 0x10`**, four stack dwords |
| 7 | Body uses all four stack args | **Falsified** — only args 3–4 (TFID) are loaded; 1–2 cleaned but unread |
| 8 | `operator_delete` never returns (Ghidra warning) | **Falsified** — `ADD ESP,4` then zero-slot + memmove |
| 9 | Returns removed count / entry* / bool | **Falsified** — always **`XOR EAX,EAX` → 0** |
| 10 | Fastcall / pure cdecl / RET 0x4 or 0x8 | **Falsified** — thiscall; **`RET 0x10`** |
| 11 | Binary search / sorted map erase | **Falsified** — linear scan begin→end |
| 12 | Case-insensitive name erase (`_stricmp`) | **Falsified** — dual int CMP on +8/+0xc; no string callee |
| 13 | Always product name without `_Inferred` | **Unproven for class** — role High from English caller; PDB class open |
| 14 | Runtime Confirmed / Terminal | **Rejected** — no Launcher; Terminal false |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| TFID @ +8/+0xc erase key | **Confirmed** | wrong key → never erase / wrong entry |
| Vector @ +0x38/+0x3c | **Confirmed** | wrong container (friends vs ignore vs +0x28 table) |
| Multi-match (no advance after erase) | **Confirmed** | partial list residual if ported as first-only |
| Always return 0 | **Confirmed** | wrong control-flow on caller |
| `RET 0x10` / four stack args | **Confirmed** | stack corruption if ported as RET 0x8 |
| Ignore-list call role | **High** | wrong system tagging |
| Product host type English | **Open** | naming only |
| Unused arg1/arg2 meaning | **Open** | caller may depend on stack shape only |

---

## 3. Cross-check

```
FUN_0080eeb0 remove-from-ignore residual:
  FUN_00573a90(tfid) → hit + entry+0x10 name
  → sprintf("%s has been removed from your ignore list.")
  → FUN_00573ce0(unused, unused, tfid_lo, tfid_hi)   [OWN]
  → CDlgTabsSocial refresh via RTTI

Parent dual IgnoreList_FindEntryByTfid_Inferred @ 0x00573a90:
  same +0x38/+0x3c, same TFID keys, READ-ONLY, RET 0x8, returns entry*
  do not merge roles or ABI widths

Sibling FUN_00573d50:
  identical erase plate at +0x28/+0x2c — different table; do not merge

Sibling FUN_005739d0:
  friends TFID find at +0x8 — do not merge
```

**Attack on “skills system core”:** partition nest is residual score parent only; live edge is social ignore remove.

**Attack on “this is the find function”:** find is `00573a90`; this unit mutates and always returns 0 with a wider RET.

**Attack on “RET 0x8 like the find twin”:** epilogue bytes are `C2 10 00` — four dwords cleaned.

---

## 4. Surviving contract for AutoCore

```csharp
// Always returns 0. Stack cleans 16 bytes (four dwords); body uses only tfid pair.
int IgnoreList_EraseEntriesByTfid(
    IgnoreListHost self,
    int unused1, int unused2,
    int tfidLo, int tfidHi)
{
    var begin = self.Begin; // +0x38
    var end = self.End;     // +0x3c
    var cur = begin;
    if (cur == end) return 0;
    var next = cur + 1; // pointer-element next
    while (cur != end) {
        var entry = *cur;
        if (entry.TfidLo == tfidLo && entry.TfidHi == tfidHi) {
            if (entry != null) Free(entry);
            *cur = null;
            // memmove compact: slide [next, end) down onto cur
            Memmove(cur, next, (end - next) * IntPtr.Size);
            self.End = end - 1; // end -= 4 bytes
            end = self.End;
            // do not advance cur/next
        } else {
            cur++; next++;
            end = self.End;
        }
    }
    return 0;
}
```

**Port traps:**

- Using friends vector offsets (+0x8) or sibling erase (+0x28) instead of ignore (+0x38/+0x3c).
- Treating as read-only find (`00573a90`) or merging ABI (`RET 0x8` vs **`RET 0x10`**).
- Advancing the cursor after erase → leaves duplicate TFID entries.
- Assuming return is count/entry*/bool (always 0).
- Skipping stack cleanup of the two unused dwords (caller still pushes four).
- Trusting decompiler noreturn on `operator_delete` (body continues).
- Using menu/target as `this` instead of multi-list host (`[client+0x31ec]` / `DAT_00d1da2c` family).

---

## 5. Residual risks

- Product type of multi-list host and entry packing beyond TFID (name@+0x10 known from find sibling).
- Unused arg1/arg2 plate origin unexplained (must still be stack-shaped correctly).
- Not skill-cast residual math — parent matrix should tag **UI / social**.

**Verdict:** **accept-with-gaps** — no CF reject; adversarial attacks on cast-role / find-merge / first-only / friends-merge / RET0x8 / noreturn / non-zero-return falsified.
