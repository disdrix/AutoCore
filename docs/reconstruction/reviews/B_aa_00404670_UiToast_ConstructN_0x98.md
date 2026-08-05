# Review B (skeptical / adversarial): `UiToast_ConstructN_0x98` / `FUN_00404670` @ `0x00404670`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00404670` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00404670_UiToast_ConstructN_0x98.md` |
| **Verdict** | **accept** on CF/stride/ABI/role; **needs-more-evidence** only on product symbol |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Grows capacity / reallocates toast vector | **Falsified** — no `operator_new`/`00403980`; pure loop + pod copy |
| 2 | Element size is `0x38` (floater) or `4` (dword) | **Falsified** — stride `add esi, 0x98`; callee copies `0x26` dwords |
| 3 | Zero-fills slots | **Falsified** — stamps from `src` via `FUN_00404710` |
| 4 | Advances `src` each element (range copy) | **Falsified** — `param_3` fixed across loop; only `dst` advances |
| 5 | `__stdcall` / `ret N` | **Falsified** — epilogue **`c3`** (cdecl); parent `ADD ESP` patterns |
| 6 | Thiscall host required (ECX = queue) | **Falsified** — free helper; ECX only loaded from phantom stack arg and unused by leaf |
| 7 | Deep-constructs strings / vtables | **Falsified** — callee dual is pure `rep movsd` POD |
| 8 | Mission grant / audio / network | **Falsified** — memory stamp only |
| 9 | Exclusive craft-response helper | **Overstated** — scaffold seed alias; primary fan-in is toast push + fill-n |
| 10 | Decompiler wrong vs bytes | **Falsified** — live decompile ≡ raw ≡ stride/call sites |
| 11 | Product name sealed | **Open** — keep structural / `FUN_*` |
| 12 | Runtime / bit-exact EXE verified | **Open** — static only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Stride `0x98` per slot | **Confirmed** | Adjacent-toast corruption / wrong end bump in parent |
| `count` iterations of pod copy | **Confirmed** | Under/over construct on multi-fill |
| Src fixed (construct-from-value) | **Confirmed** | Wrong if ported as range-to-range copy |
| cdecl free helper | **Confirmed** | Stack imbalance if stdcall assumed |
| Phantom 4th/5th stack args unused for CF | **Confirmed** | Over-specifying ABI confuses ports |
| Toast-element role | **High** | Mis-wire as generic ConstructN of other width |
| Product C++ name | **Open** | Docs only |

---

## 3. Surviving contract for AutoCore

```
// cdecl (dst, count, src); SEH frame present
void UiToast_ConstructN_0x98(void* dst, int count, const void* src):
  while count != 0:
    UiToast_PodCopyElement_0x98(dst, src)   // 0x98 POD bytes; dst null-gated inside leaf
    dst += 0x98
    count -= 1

// NOT growth. NOT end-pointer update. NOT range-to-range relocate.
// Callers: Client_UiToastQueue_Push (count=1), FUN_00404130 (fill-n + return end).
```

---

## 4. Falsification notes

### 4.1 “This is vector::insert”

Insert / 1.5× growth lives at `FUN_00403980` / `FUN_0040c720`. This VA never reads begin/end/cap triad.

### 4.2 “Parent decompile shows 5 args, so signature is 5”

Parent dual (`Client_UiToastQueue_Push`) already sealed: **phantom thiscall args** with `ADD ESP,0x14`. Body only consumes three formals. Image loads `[ebp+0x14]` into `ECX` but `FUN_00404710` is stdcall leaf that ignores `ECX`.

### 4.3 Confusion with floater ConstructN

`0x00404600` is the **0x38** twin. Same CF shape; different stride and pod-copy leaf.

### 4.4 Craft-only naming

Scaffold `Named_CalleeOf_…_RecvCraft…` is call-graph residue from one toast push site, not ownership.

---

## 5. Open questions

1. Retail symbol.
2. Dual residual on `FUN_00404130` (thin wrapper; role known).
3. Bit-exact / runtime — open.

**Verdict:** **accept** on sealed CF, stride, cdecl ABI, and toast ConstructN role. Reject growth / deep-ctor / mission-side-effect overclaims. Product symbol open.
