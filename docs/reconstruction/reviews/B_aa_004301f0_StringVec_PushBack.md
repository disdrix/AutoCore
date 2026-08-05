# Review B (skeptical / adversarial): `aa_004301f0` StringVec_PushBack

| Field | Value |
|---|---|
| **Stable ID** | `aa_004301f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W33-D) |
| **Counterpart** | `reviews/A_aa_004301f0_StringVec_PushBack.md` |
| **Scratch** | `tmp/a_004301f0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | cdecl void only | **Falsified** — `8B F9` thiscall; `C2 04 00` RET 4 |
| 2 | Always grows / always inserts | **Falsified** — capacity gate with in-place `FUN_00431700` |
| 3 | Returns iterator in EAX | **Falsified** — void; slow path writes unused out-it |
| 4 | Element stride 4 or 0x18 | **Falsified** — `/0x1c` magic `0x92492493` twice |
| 5 | Null begin treated as empty with capacity | **Falsified** — null begin forces size=0 then falls to insert path |
| 6 | `FUN_00431700` takes 5 live formals | **Weakened** — caller pushes 5; callee decompile uses dest/count/value only |
| 7 | VOG_DEBUG scaffold name sealed | **Rejected** — structural `StringVec_PushBack` |
| 8 | Same as push_front | **Falsified** — always targets **end**; push_front uses insert-at-begin via `FUN_00969830` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall + 1 stack arg + RET 4 | **High** | ABI crash |
| stride 0x1c | **High** | corrupt adjacent elems |
| size < capacity fast path | **High** | missed O(1) push |
| slow path = insert-at-end | **High** | wrong grow site |
| Nested construct-n details | **Med** | partial construct bugs |
| Product plate | **Low** | naming |
| Runtime | **Open** | matrix |

---

## 3. Cross-check against raw + bytes + callers

```
// FUN_004301f0
if begin && size < cap:
  construct_n(end, 1, value); end += 0x1c
else:
  StringVec_InsertOne(this, &scratch, end, value)

// Callers: listing/path collect (W32-D), AssManager helpers, path find push
// Pair: StringVec_InsertOne (W32-A), StdVector_InsertN_BasicString (W32-B)
```

Decompile ≡ hex for capacity gate and both callees. W32-A already named this site as capacity-full push_back fallback.

---

## 4. Surviving contract for AutoCore

```
// Port as vector push_back:
void StringVec_PushBack(StringVecShell* v, const std::string& value) {
  if (v->size() < v->capacity()) {
    // construct at end; ++end   // FUN_00431700 path
  } else {
    v->insert(v->end(), value);  // FUN_00430310 → FUN_004306b0
  }
}
// Elem type size must be 0x1c. Do not return iterator. RET 4 thiscall.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI, stride, dual-path push_back, and insert-at-end fallback. Nested construct-n dual + product English open → **accept-with-gaps**.
