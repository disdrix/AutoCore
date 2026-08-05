# Review B (skeptical / adversarial): `aa_00419ad0` CNDHash_BucketChainTouchRepair

| Field | Value |
|---|---|
| **Stable ID** | `aa_00419ad0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W19-D) |
| **Counterpart** | `reviews/A_aa_00419ad0_CNDHash_BucketChainTouchRepair.md` |
| **Verdict** | **accept** on sealed CF; reject listed false claims |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | ECX-thiscall like `aa_00537d30` | Body uses `[edi+4]`; insert site `mov edi, bucket` before CALL | **Falsified** |
| 2 | Same node offsets as `00537d30` (`touch+4` / `next+0xC`) | Bytes `88 48 08` / `8b 40 10` / `89 5e 10` | **Falsified** |
| 3 | Frees cycle tail nodes | No `delete`/`free`; only null next | **Falsified** |
| 4 | Debug-only / `#ifdef` integrity | Unconditional CALL from insert + unlink (4 xrefs) | **Falsified** |
| 5 | Compares u64 keys or unlinks ordered list | Only +8/+0x10 topology | **Falsified** |
| 6 | Returns error code in EAX | Bare void ret; no EAX set for status | **Falsified** if claimed |
| 7 | Scaffold auto-seed "VOG_DEBUG_STOP callee" is product name | String is HashListError; STOP is sibling log in insert path | **Overstated** |
| 8 | Identical to `Util_HashListError_Repair_00537d30` | Same string/algorithm family, **different ABI+layout** | **Falsified** as same unit |
| 9 | Bit-exact / runtime verified | Static dual only | **Fail** if claimed |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EDI bucket ABI | **High** | Wrong register in wrappers |
| touch@+8 / next@+0x10 | **High** | Corrupts wrong fields |
| Cycle sever only (no free) | **High** | Double-free if port invents free |
| Not ECX clone of 00537d30 | **High** | Wrong helper substitution |
| Product identifier spelling | **Low–Med** | Naming only |
| Severed-node ownership | **Med** | Leak residual if mis-owned |

---

## 3. Cross-check

| Item | Result |
|---|---|
| Raw ≡ live decompile | **Yes** |
| Body hex via `read_memory` | **Yes** — starts `8b4704…`, ends `…5e5bc3` |
| String @ `0x00a64710` | **Yes** full HashListError text |
| Insert site EDI setup | **Yes** `8b 3c 81` … `e8` to this |
| Unlink dual always calls | **Yes** W18-P sealed (`aa_00419b80`) |
| Clone `00537d30` | **Different VA / offsets / ECX** |

**Attack on “this is ECX-thiscall util shared with free-list”:** **Fails** — this VA is EDI + u64-node layout.

**Attack on “must free after sever”:** **Fails** — body nulls next only; free is not present.

---

## 4. Surviving contract for AutoCore

```
// EDI = CNDHash bucket header* (head at +4)
// node.touch @ +8 (u8); node.next @ +0x10
// walk mark=1; healthy clear=0; cycle: log(1, HashListError…), prev->next=0, clear
// bare ret; no free; no keys; no ordered list
```

**Falsified port mistakes:**

- Calling with ECX instead of EDI (or substituting `00537d30` body).
- Using touch@+4 / next@+0xC from the other clone.
- Freeing after sever inside this helper.
- Treating as optional debug-only check.

---

## 5. Open questions

1. Product/PDB symbol.
2. Ownership of severed tails.
3. Runtime / bit-exact.

**Verdict:** **accept** — sealed CF/ABI/layout; reject ECX-clone and free-on-repair myths.
