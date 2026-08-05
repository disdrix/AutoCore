# Review B (skeptical / adversarial): `aa_00745ee0` NDResource_AcquireInnerObject

| Field | Value |
|---|---|
| **Stable ID** | `aa_00745ee0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00745ee0_NDResource_AcquireInnerObject.md` |
| **Verdict** | **accept-with-gaps** on CF (acquire/refcount/CS sealed; product English residual open) |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | This is a pure getter of `this+0x8` with no side effects | Body always `+1` refcount and writes `+0x1c` time | **Falsified** — mutates shell |
| 2 | Function takes a path / key string argument | Plain `ret`; ECX-only; 0 stack args | **Falsified** |
| 3 | Return is the resource shell (`this`) | Bytes end `mov esi,[esi+8]` / `mov eax,esi` | **Falsified** — returns **inner** |
| 4 | CS is always taken | Gated on `byte this+0x38` | **Falsified as always** |
| 5 | Decompiler “second Enter” is really a Leave misread | EBX=Enter IAT; EBP=Leave IAT; Enter×2 then Leave×2 | **Falsified** — nested Enter is real |
| 6 | Timer store is integer tick | `fstp dword [esi+0x1c]` after `FUN_0076c330` | **Falsified as int** — **float32** |
| 7 | Null-inner path is a no-op / early return 0 | `call [vtbl+8]` on shell then re-load `+0x8` | **Falsified as no-op** — Release attempted |
| 8 | This unit decrements refcount | Only `add [+0x10],1`; decref is `FUN_00745ea0` / callers | **Falsified** |
| 9 | `param_1[0xe]` is a dword flag | Checks use **byte** `[this+0x38]` | **Sealed as u8 flag** (low byte of dword slot) |
| 10 | Only used by NDXml | 18 xrefs across gfx/effect/anim/xml | **Falsified as xml-only** |
| 11 | Inner `+4` COM Release is **inside** this function | That is caller `NDXml` after return | **Falsified** — caller residual |
| 12 | Recursive CS not required | Nested Enter without Leave between | **Survives as requirement** when flag set |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall ECX shell, EAX = `*(this+0x8)` | **High** | Wrong pin / UAF in ports |
| Refcount `+0x10` increment | **High** | Leak / premature free |
| Optional CS `+0x20` / flag `+0x38` | **High** | Race or deadlock |
| Nested Enter×2 when locked | **High** | Deadlock if CS non-recursive |
| Null → vtbl+8 shell Release | **High** | Leaked failed loads |
| `+0x1c` float touch time | **High** | Wrong LRU / TTL if treated as int |
| `FUN_0076c330` English name | **Open** | Doc only |
| vtbl+8 product symbol | **Open** | Doc only |
| Whether Release may free `this` before re-read `+0x8` | **Open** | UAF analysis residual |
| Runtime / bit-exact | **Open** | Unverified live |

---

## 3. Cross-check raw + live bytes

```
00745ee0  push -1 / push LAB_009ac157 / FS:[0] SEH
00745ef0  mov  ebx, [0x009c61bc]       ; EnterCriticalSection IAT
00745ef9  mov  esi, ecx                 ; this
00745efb  cmp  byte [esi+0x38], 0
00745f00  lea  edi, [esi+0x20]         ; CS*
00745f03  je   skip_enter1
00745f05  push edi / call ebx          ; Enter #1
00745f0a  mov  [esp+0x1c], 0           ; SEH state
00745f12  add  dword [esi+0x10], 1     ; refcount++
00745f16  call FUN_0076c330
00745f1b  fstp dword [esi+0x1c]        ; float touch time
00745f1e  cmp  byte [edi+0x18], 0      ; == [this+0x38]
00745f22  je   skip_enter2
00745f24  push edi / call ebx          ; Enter #2 (nested)
00745f27  cmp  dword [esi+0x8], 0
00745f2b  mov  ebp, [0x009c61b8]       ; LeaveCriticalSection IAT
00745f31  setne bl                     ; bl = (inner != 0)
00745f34  cmp  byte [edi+0x18], 0
00745f38  je   skip_leave1
00745f3a  push edi / call ebp          ; Leave #1
00745f3d  test bl, bl
00745f3f  jne  skip_release
00745f41  mov  eax, [esi]
00745f43  mov  ecx, esi
00745f45  call [eax+0x8]               ; shell Release
00745f48  cmp  byte [edi+0x18], 0
00745f4c  mov  esi, [esi+0x8]          ; re-sample inner
00745f4f  je   skip_leave2
00745f51  push edi / call ebp          ; Leave #2
00745f54  … SEH teardown …
00745f5f  mov  eax, esi                ; return inner
00745f66  ret
00745f70  int3 pad …
```

Live `read_memory` hex (body through `ret`):

`6aff6857c19a0064a100000000506489250000000051538b1dbc619c0055568bf1807e3800578d7e20897c2410740357ffd3c744241c0000000083461001e80d640200d95e1c807f1800740357ffd3837e08008b2db8619c000f95c3807f1800740357ffd584db75078b068bceff5008807f18008b7608740357ffd58b4c24145f8bc65e5d5b64890d0000000083c410c3`

Three `decompile_function` reps (2026-07-29) match 2026-07-23 raw control flow; bytes confirm nested Enter and `fstp` float store.

---

## 4. Surviving contract for AutoCore

```
void* NDResource_AcquireInnerObject(NDResource* self):
  // __thiscall; no stack args; returns inner or NULL
  if (self->lockFlag)              // +0x38 u8
    EnterCriticalSection(&self->cs) // +0x20
  self->refcount += 1               // +0x10
  self->lastTouch = NowFloat()      // +0x1c ← FUN_0076c330 / fstp
  if (self->lockFlag)
    EnterCriticalSection(&self->cs) // nested
  inner = self->inner               // +0x08
  if (self->lockFlag)
    LeaveCriticalSection(&self->cs)
  if (inner == NULL)
    self->Release()                 // vtbl +0x08
  inner = self->inner               // re-sample
  if (self->lockFlag)
    LeaveCriticalSection(&self->cs)
  return inner
```

- Pair with shell **decref** (`FUN_00745ea0` or inlined `refcount--` under same flag/CS) after consumer finishes.
- Do **not** assume return is the shell; consumers may use `*(inner+4)` as iface (XML path).
- CS must be **recursive** if `lockFlag` is ever set.
- Port must stamp **float** time, not integer, if any LRU/TTL depends on `+0x1c`.

---

## 5. Residual (do not over-claim)

1. Product / PDB English for `FUN_0076c330` and vtbl+8.
2. Whether null-inner Release can free `self` before the second `*(self+0x8)` load (UAF residual — needs Release body dual, not owned here).
3. Semantic meaning of lockFlag producers (who sets `+0x38`).
4. Live runtime / image bit-exact.
5. Exhaustive per-caller ECX provenance beyond NDXml sample (parent residual).
