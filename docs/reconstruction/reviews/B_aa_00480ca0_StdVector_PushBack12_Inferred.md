# Review B (skeptical / adversarial): `aa_00480ca0` StdVector_PushBack12_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00480ca0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W18-O) |
| **Counterpart** | `reviews/A_aa_00480ca0_StdVector_PushBack12_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Element size is 4 (dword push sibling) | **Falsified** — `/0xc`, `add 0xC`, magic `0x2AAAAAAB` |
| 2 | True `__thiscall` ECX=this | **Falsified** — `mov edi,eax`; callers set **EAX** |
| 3 | Value is a single ECX dword (decompiler `param_1`) | **Falsified as ABI** — callers `LEA EBX,&local12`; fast path `mov edx,ebx` into 3-dword copy |
| 4 | Always heap-allocates | **Falsified** — fast path is in-place copy + end bump |
| 5 | Insert / mid-insert API | **Falsified** — only end append; slow helper still end-oriented from this unit |
| 6 | Leaf (no callees) | **Falsified** — `0042acc0` / `0042a710` |
| 7 | Product name `StdVector_PushBack12` is proven | **Sustained as gap** — structural INFERRED only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Stride 12 | **Confirmed** | Corrupt adjacent elements / wrong capacity math |
| EAX vector / EBX src* | **Confirmed** | Wrong register in port → silent data loss |
| Fast vs slow split | **High** | Unnecessary realloc or missed grow |
| Grow freelist policy | **Open** | Memory bugs if porting slow path without dual |
| Element product type | **Open** | Over-typed struct shared across unrelated callers |

---

## 3. Cross-check against raw + bytes

```
if begin && size12 < cap12:
  copy12(end, *EBX); end += 12; return
grow_insert_end(vector, end, EBX)
```

Clean must **not** invent dword stride, ECX-this, or multi-element push. Sibling pattern: `StdVector_PushBackDword` (`0x004406e0`) is **stride 4** — different unit.

---

## 4. Surviving contract for AutoCore

```c
// Port only if a server/container needs 12-byte vector push with same layout.
// header: +4 begin, +8 end, +0xc capacityEnd (byte pointers or Element12*)
// push: if room, memcpy 12 bytes to end and bump; else grow.
```

Do **not** assume Element12 is Vec3 float — callers use thread IDs / mixed fields too.

---

## 5. Open questions

1. Product symbol.
2. Exact grow geometry in `FUN_00480d20`.
3. Whether +0 of header is unused cookie vs allocator back-pointer (untouched here).

**Verdict:** **accept-with-gaps**
