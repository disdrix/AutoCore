# Review B (skeptical / adversarial): `aa_00430310` StringVec_InsertOne

| Field | Value |
|---|---|
| **Stable ID** | `aa_00430310` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W32-A) |
| **Counterpart** | `reviews/A_aa_00430310_StringVec_InsertOne.md` |
| **Scratch** | `tmp/a_00430310.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | cdecl void only | **Falsified** — `8B F9` thiscall; `C2 0C 00` RET 12 |
| 2 | In-place overwrite without grow | **Falsified** — always `FUN_004306b0` with count=1 (shift/grow paths inside) |
| 3 | Returns iterator in EAX | **Falsified** — void; stores through `*out_iterator` |
| 4 | Element stride 4 or 0x18 | **Falsified** — `/0x1c` magic `0x92492493` twice |
| 5 | Index taken after insert (stale pos) | **Falsified** — index computed **before** call; rebuild uses new begin |
| 6 | Only used for push_front | **Falsified** — also `FUN_004301f0` insert-at-end capacity miss |
| 7 | VOG_DEBUG scaffold name sealed | **Rejected** — structural `StringVec_InsertOne` |
| 8 | `param_4` is integer width | **Falsified** — value pointer into `FUN_004306b0` which copy-ctors a `basic_string` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall + 3 stack args + RET 12 | **High** | ABI crash |
| stride 0x1c | **High** | corrupt adjacent elems |
| index-before-insert rebuild | **High** | dangling iter after realloc |
| count always 1 | **High** | multi-insert mis-port |
| Nested grow details | **Med** | capacity bugs if reimplemented |
| Product plate | **Low** | naming |
| Runtime | **Open** | matrix |

---

## 3. Cross-check against raw + bytes + callers

```
// FUN_00430310
index = empty? 0 : (pos-begin)/0x1c
FUN_004306b0(this, pos, 1, value)
*out = begin' + index*0x1c

// FUN_00969830: pos = begin  → push_front
// FUN_004301f0: pos = end    → push_back via insert when no spare capacity
```

Decompile ≡ hex for control and constants. Nested `FUN_004306b0` decompile confirms value is `basic_string*` and shell uses +4/+8/+0xc.

---

## 4. Surviving contract for AutoCore

```
// Port as vector insert-one with iterator out:
iterator StringVec_InsertOne(StringVecShell* v, iterator pos, const std::string& value) {
  size_t index = v->empty() ? 0 : (pos - v->begin());
  v->insert(pos, value);           // FUN_004306b0 path
  return v->begin() + index;
}
// Do not assume no reallocation; do not return EAX iterator.
// Elem type size must be 0x1c (MSVC basic_string layout of this binary).
```

---

## 5. Verdict

Adversarial pass confirms A on ABI, stride, single insert, and iterator rebuild. Nested grow dual (W32-B) + product English open → **accept-with-gaps**.
