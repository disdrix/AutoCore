# Review B (skeptical / adversarial): `aa_00406e50` StdVector_UninitializedFillN_Elem0x28_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00406e50` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (WQ9G-H) |
| **Counterpart** | `reviews/A_aa_00406e50_StdVector_UninitializedFillN_Elem0x28_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` + `read_memory` + callee/parent decompile. **No** `disassemble_bytes`.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Decompiler `int FUN_00406e50(void)` is complete | **Falsified as ABI** — EDI/ESI + 1 stack formal required; unaff_* not optional |
| 2 | This is grow / insert-N itself | **Falsified** — no capacity math; only ConstructN + pointer advance |
| 3 | Stride is 4 or 0x1c (Pod28) | **Falsified** — `esi*5*8` = ×0x28; callee advances +0x28 |
| 4 | Tree neighborhood leaf = tree free/min/max | **Falsified** — vector fill-n only |
| 5 | `ret 0xC` three stack args like toast fill-n | **Falsified** — **`ret 4`**; dst/count in registers |
| 6 | Construct copies non-POD / calls complex ctor | **Falsified** — leaf `FUN_00409f30` is 10×dword store loop |
| 7 | Multiple independent callers | **Fails as multi-domain** — only `FUN_00408050` (2 sites) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EDI/ESI + ret 4 ABI | **High** | Wrong end pointer / stack |
| Stride 0x28 end math | **High** | Misaligned elements |
| Role = fill-n only | **High** | Invented growth |
| PodCopy 0x28 leaf | **High** | Wrong construct semantics |
| Product demangle | Medium | Naming only |
| Runtime | Open | — |

---

## 3. Cross-check against raw + bytes

```
push value; push ecx; mov ecx, value; push esi; push edi
call FUN_00409d40
add esp, 0x10
eax = edi + esi*0x28
ret 4
```

Parent `00408050`: after uninit-copy split, calls this with local 0x28 template (`local_58[10]`) to fill the insert hole.

Do **not** confuse with `Pod28` (0x1c) family. Do **not** treat as tree leaf despite address near insert/buynode cluster.

---

## 4. Surviving contract for AutoCore

```csharp
// byte* UninitializedFillN(byte* dst, int count, in Elem0x28 value)
// EDI=dst, ESI=count, stack &value, ret 4 → dst+count*0x28
// construct = FUN_00409d40 → FUN_00409f30 (10 dwords)
```

Shared insert helper; pair with insert-N `FUN_00408050` and insert-one rebind `00406de0` (this wave).

---

## 5. Verdict

**accept-with-gaps** — adversarial checks confirm fill-n leaf CF/ABI/stride. Residual demangle + undualed ConstructN + runtime. Not reject.
