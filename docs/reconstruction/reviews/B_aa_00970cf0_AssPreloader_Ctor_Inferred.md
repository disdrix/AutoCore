# Review B (skeptical / adversarial): `aa_00970cf0` AssPreloader_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00970cf0` |
| **VA** | `0x00970cf0` |
| **Canonical name** | `AssPreloader_Ctor_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_00970cf0_AssPreloader_Ctor_Inferred.md` |
| **System** | assets / AssPreloader construction |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is ensure/seed (parent logic) | Body only inits fields; no list walk / push | **Falsified** ensure claim |
| 2 | Thiscall ECX=self | Bytes load self from stack (`mov esi,[esp+…]`); parent pushes mem then host | **Falsified** thiscall model |
| 3 | Plain RET / one formal | Epilogue **`C2 08 00`**; two pushes at sole call site | **Falsified** |
| 4 | Object size unknown / not 0x114 | Sole parent `operator_new(0x114)` + field through `+0x110` | **Falsified** size-open claim |
| 5 | No Win32 deps | `CreateEventA` + 4× `InitializeCriticalSection` | **Falsified** pure-software claim |
| 6 | Single tree only | Two alloc helpers: `005ae2b0` (0x1c) + `00439770` (0x18) | **Falsified** |
| 7 | host@+0x110 is invent | Explicit store of param_2; family methods read `+0x110` | **Falsified** invent claim |
| 8 | Seed ring is @+0x80 only | Ensure `add edi,0xAC`; CS@+0xC0 matches header+0x14 | **Falsified** wrong-ring claim |
| 9 | Client_InitInstance domain plate | No strings/RTTI on VA; structural AssPreloader family only | **Agree** reject scaffold |
| 10 | Returns void | `mov eax,esi` before teardown | **Falsified** void claim |
| 11 | Same as retire (`00970e50`) | Distinct VA/size/CF; retire is method on live object | **Falsified** merge |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| RET 8 / (self*, host*) / returns self | **Confirmed** | Stack imbalance / wrong host |
| Size 0x114 / vtbl / event | **Confirmed** | Wrong alloc / lifetime |
| Map head + second tree wiring | **Confirmed** | Broken iterators later |
| Four CS banks + lockEnable=1 | **Confirmed** | Unlock crashes / races |
| Seed ring header @+0xAC | **High** | Ensure seed wrong container |
| Bank A–C product roles | **Probable** | Mis-wire non-seed rings |
| SEH partial-ctor teardown | **Open** | Leak on throw mid-init |
| Product English | **Open** | Naming only |
| Runtime | **Open** | No live construct capture |

---

## 3. Cross-check against raw / live / bytes

```
raw scaffold CF ≡ live batch_decompile (2026-08-04);
body 348 B ends C2 08 00; pad CC then FUN_00970e50 (retire).

Prolog: FS:[0] SEH LAB_009accf1
self = [esp+…] after push ebx/ebp/esi
*self = PTR_FUN_00aa9a94
CreateEventA via IAT [0x009c61fc] → [self+4]
FUN_005ae2b0 → [self+0x14]; isnil/circular
InitializeCriticalSection ×4 via IAT [0x009c61ec] @ +0x30/+0x60/+0x90/+0xC0
FUN_00439770 → [self+0xE0]; isnil/circular
[self+0x110] = host (param_2)
return self; add esp,0xC; ret 8
```

### Parent trap

Decompiler of ensure may show `FUN_00970cf0()` with **no** formals — **bytes win**: `push host; push mem; call`. Do not port as zero-arg or thiscall-only.

### Layout trap

Do **not** treat bank zero offsets as linear `vector{begin,end,cap}` starting at each CS. Seed path uses GuardedVector header `@+0xAC` with CS at header+0x14 (`+0xC0`) and lockEnable at header+0x2c (`+0xD8`) per W32-N dual.

### Alias trap

Scaffold `Named_CalleeOf_*Client_InitI*` is xref-noise only — reject as product plate.

---

## 4. Surviving contract for AutoCore

```
AssPreloader_Ctor_Inferred(self*, host*):
  // after operator_new(0x114)
  install vtbl PTR_FUN_00aa9a94
  self+0x04 = CreateEventA(0,0,0,0)
  map head = StdTree_AllocNode_0x1c → +0x14 (isnil/circular); size+0x18=0
  init 4× GuardedVector+CS banks (seed header usable at +0xAC)
  tree2 = RbTree_AllocEmptyNode → +0xE0 (isnil/circular); size+0xE4=0
  self+0x110 = host
  return self; ret 8

Sole retail caller:
  AssManager_EnsureAssPreloader (0x0075d3c0) after new(0x114)

AutoCore must NOT:
  - fold ensure seed list-walk into this VA
  - drop host@+0x110 (enqueue/worker depend on it)
  - use wrong ring base for seed (+0x80 vs +0xAC)
  - invent thiscall ECX ABI
  - claim product English Confirmed without RTTI/string
```

---

## 5. Verdict

**accept-with-gaps** — adversarial checks fail to break ctor ABI/size/layout contract; residual is product English, bank roles, SEH teardown, runtime.
