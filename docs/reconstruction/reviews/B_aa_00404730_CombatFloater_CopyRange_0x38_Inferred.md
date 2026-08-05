# Review B (skeptical / adversarial): `aa_00404730` CombatFloater_CopyRange_0x38_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00404730` |
| **VA** | `0x00404730` |
| **Canonical name** | `CombatFloater_CopyRange_0x38_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00404730_CombatFloater_CopyRange_0x38_Inferred.md` |
| **System** | missions-progression / combat floater UI |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is the pod-copy **leaf** | Leaf is `FUN_004046f0`; this only loops + calls it | **Falsified** leaf claim |
| 2 | Element size 4 / dword vector | Stride **`0x38`**; leaf `ecx=0xe` dwords | **Falsified** dword-vector |
| 3 | Fills from a single template | Src advances with dst (range-to-range); fill is `00404600` / `004044e0` | **Falsified** template-fill |
| 4 | Owns growth / `operator_new` | Pure copy; growth is `00403680` | **Falsified** growth role |
| 5 | `__stdcall` / `ret 12` | Epilogue is **`c3`** (cdecl); trampoline parent uses `ret 0xC` | **Falsified** stdcall-on-this-VA |
| 6 | Deep-constructs floaters (heap strings) | Pod leaf is pure `rep movsd`; no other calls | **Falsified** owning-ctor |
| 7 | Part of XP / mission award | Storage relocate only | **Falsified** award role |
| 8 | Product name sealed | Structural / `_Inferred` | **Open** |
| 9 | Decompiler 3 formals wrong | Bytes use `[ebp+8/+c/+10]`; `[ebp+14]` only dead ECX | **Survives** as 3 used formals |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Stride `0x38` loop | **Confirmed** | Wrong floater layout / overrun |
| Callee = pod `004046f0` | **Confirmed** | Deep-copy invented |
| Return advanced dst | **Confirmed** | Caller end pointer wrong |
| cdecl `ret` | **Confirmed** | Stack imbalance if stdcall assumed |
| SEH present | **Confirmed** | Low (ports may omit EH) |
| Floater relocate role | **High** | Mis-wire generic memcpy of other width |
| 4th stack slot meaning | **Low / unused** | Do not invent 4th formal semantics |
| Product C++ name | **Open** | Docs only |

---

## 3. Live ≡ raw

```
Live decompile 0x00404730 ≡ raw:
  SEH setup
  for (src=param_1; src!=param_2; src+=0x38) {
    FUN_004046f0(param_3 /*dst*/, src);
    param_3 += 0x38;
  }
  return param_3;
```

`read_memory` epilogue: `8bc7 … 5f5e5b8be55dc3` → `eax=edi` (dst), cdecl `ret`.

Parent dual (`004044c0`) already documents this VA as the **real worker** behind the uninitialized-copy trampoline. Leaf dual seals **0x38** width.

---

## 4. Surviving contract for AutoCore

```
// cdecl
// CombatFloater_CopyRange_0x38(srcBegin, srcEnd, dst) → advanced_dst
//   for each 0x38 POD in [srcBegin,srcEnd): PodCopy0x38(dst, src); dst += 0x38
//
// NOT owning ctor. NOT vector growth. NOT template fill.
// Sole caller: FUN_004044c0 (relocate helper for InsertN).
// Leaf: FUN_004046f0 (14 dwords, null-check dst only).
```

---

## 5. Falsification notes

### 5.1 “Uninitialized_copy” vs “copy”

Parent is named UninitializedCopy (MSVC relocate semantics). Body is **POD memcpy of live elements** — no ctor calls beyond the pod leaf. Do not invent C++ non-trivial ctors here.

### 5.2 Confusing with ConstructN (`00404600`)

ConstructN takes **count + single template**; this takes **src range** and advances both pointers.

### 5.3 Stack-arg inflation from trampoline

`004044c0` does `add esp, 0x14` after call (5 pushes). That does **not** mean this worker has five meaningful formals; only three drive CF. Ports should use `(srcBegin, srcEnd, dst)`.

---

## 6. Open questions

1. Retail symbol.
2. Full field map of the 0x38 floater POD (owned by packers / enqueue, not this worker).
3. Bit-exact / runtime — open.

**Verdict:** **accept-with-gaps** on sealed CF, stride, leaf callee, cdecl return-dst, sole-caller role. Reject leaf/growth/template-fill/award overclaims. Product name open.
