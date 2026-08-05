# Review B (skeptical / adversarial): `aa_004970b0` Class_009c7a1c_CompleteDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_004970b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W28-M) |
| **Counterpart** | `reviews/A_aa_004970b0_Class_009c7a1c_CompleteDtor.md` |
| **Scratch** | `tmp/a_004970b0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is the scalar deleting dtor | **Falsified** — body has no flags test / no `operator_delete(this)`; scalar is `FUN_004975e0` (vtbl[0]) |
| 2 | `FUN_00497360()` destroys root `this` | **Falsified** — bytes `LEA ECX,[ESI+0x0C]`; list is subobject |
| 3 | Freeing `+0x30` triple conflicts with list @ +0x0C | **Careful** — list layout is head@list+4 / size@list+8 → absolute `this+0x10` / `this+0x14`. Buffer triple at `+0x30` is a **different** field after list storage; both sealed as separate steps |
| 4 | Ghidra noreturn on `operator_delete` truncates body | **Falsified** — each delete is CALL+ADD ESP,4+zero stores; full 304 B path reaches list + RET |
| 5 | cdecl / stack this | **Falsified** — `8B F1`; sole caller uses thiscall |
| 6 | Name `_den.pgm` / map layer product plate | **Overstated** — adjacent rdata only; not referenced by body |
| 7 | Decompile ≡ complete ECX targets | **Partial** — high-level order yes; LEA list target requires bytes |
| 8 | Same as `StdList_Destroy` alone | **Falsified** — multi-member dtor; list is last step only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Complete dtor vs scalar-deleting | **High** | Double-free / miss free |
| List subobject +0x0C | **High** | Corrupt wrong object |
| Vector stride 0x28 + cookie | **High** | Heap corruption |
| Six buffer offsets | **High** | Leak / UAF |
| Product English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + caller

```
// FUN_004975e0 (vtbl[0]):
mov esi, ecx
call FUN_004970b0
test flags, 1 → operator_delete(this)
ret 4
```

Live decompile 2026-07-29 ≡ raw 2026-07-23 CF. Full body hex seals LEA list, six free sites, vector path, SEH epilogue.

---

## 4. Surviving contract for AutoCore

```
// Port complete dtor only (not scalar wrapper):
Class_009c7a1c_CompleteDtor(obj);
// - vtbl = PTR_FUN_009c7a1c first
// - destroy 0x28-stride array at +0x28 with element dtor FUN_005b8000
// - free six buffer triples at 0xBC,0xAC,0x9C,0x40,0x30,0x1C
// - StdList_Destroy_FreeHead(obj+0x0C)  // NOT obj
// ScalarDeleting = body + optional operator_delete(this)  // separate VA
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/list LEA/false-noreturn. Product name residual → **accept-with-gaps**.
