# Review B (skeptical / adversarial): `aa_005114e0` StdVector_CopyCtor_Elem0x10_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005114e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY R13-029; dual start 2686) |
| **Counterpart** | `reviews/A_aa_005114e0_StdVector_CopyCtor_Elem0x10_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is vector **copy-assign** / operator= | **Falsified** — zeros dest triad without freeing prior buffer; pure ctor shape (SEH state 0 around first alloc) |
| 2 | This is **InsertN / PushBack / ConstructN** | **Falsified** — no where-iterator, no count arg, no growth formula; single range-copy of full source |
| 3 | Element stride **0x28 / 12 / dword** | **Falsified** — `SAR/SHL 4` only; max gate `0x0FFFFFFF` matches sizeof(T)=0x10; PodCopy peer `00409f70` is 4 dwords |
| 4 | cdecl / no this | **Falsified** — `MOV ESI,ECX`; sites `LEA ECX,[ESI+0x10]` / stack LEA before CALL |
| 5 | `RET` bare / `RET 8` / `RET 0x10` | **Falsified** — epilogue `C2 04 00` (RET 4); one stack src pointer |
| 6 | Tree insert / rebalance / buynode itself | **Falsified** — no color/isnil/link; pure vector; buynode `005118b0` is caller |
| 7 | Skill / ability exclusive product logic | **Falsified** — generic STL container ctor; system tag is residual partition only |
| 8 | Same unit as InsertN Elem0x10 `00408640` | **Falsified** — different VA, ABI (thiscall+RET4 vs fastcall count/EDX vec+RET8), no 1.5× growth |
| 9 | `FUN_004540b0` returns clamped size | **Falsified** — noreturn length_error (`"vector too long"` family); decomp assignment is false |
| 10 | Merge name without Elem0x10 disambiguator | **Falsified** — stride-specific family; other elem sizes have distinct duals |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Copy-ctor CF (zero + alloc + uninit_copy) | **High** | Wrong container op |
| ABI thiscall + RET 4 + return this | **High** | Stack corruption |
| Stride 0x10 / max 0x0FFFFFFF | **High** | Wrong element size / OOB |
| Distinct from InsertN/assign/tree ops | **High** | Silent merge bug |
| Product type English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against parent + peers

```
// Parent dual R12-014 aa_00511950 InsertAndRebalance Node24 isnil21:
//   value_type = int key @ node+0xC + vector payload @ node+0x10
// Nested residual buynode 005118b0 (not OWN):
//   operator_new(0x24); key=*value; CALL 005114e0 on [ESI+0x10] / value+4; color; isnil0
// InsertOrFind residual 00511b40 (not OWN):
//   skill-map path FUN_0050ba90 builds value via two 005114e0 copies then insert
// Elem0x10 family (dualed elsewhere):
//   PodCopy 00409f70 / ConstructN 00409e20 / InsertN 00408640 / UninitFillN 00407000
// Range worker residual FUN_005dd920:
//   for (p=begin; p!=end; p+=4 dwords) copy 4 dwords to dest++
```

---

## 4. Surviving contract for AutoCore

```
// Port as shared std::vector copy-ctor for Elem0x10 (16-byte POD):
//  - thiscall; ECX = dest vector*; stack = const src vector*; ret 4; return this
//  - triad at +4 begin / +8 end / +0xC capEnd; +0 allocator untouched
//  - n = (end-begin)>>4; empty → zero triad and return
//  - if n > 0x0FFFFFFF → throw length_error (FUN_004540b0 noreturn)
//  - new(n*0x10); uninit_copy 4-dword elements; end = write cursor
// Do NOT merge with InsertN 00408640, PodCopy leaf 00409f70, or tree insert 00511950.
// Pair with residual buynode 005118b0 and parent dual Node24 insert; residual range-copy 005dd920.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/stride/role/disambiguation from InsertN and tree ops. Product residual → **accept-with-gaps**. Runtime Confirmed: **not claimed**.
