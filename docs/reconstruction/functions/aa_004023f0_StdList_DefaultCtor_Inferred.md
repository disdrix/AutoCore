# Function record: StdList_DefaultCtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004023f0` |
| **Canonical name** | `StdList_DefaultCtor_Inferred` |
| **Ghidra name** | `FUN_004023f0` |
| **Address** | `0x004023f0`–`0x00402405` inclusive (**22 B** / `0x16`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | shared MSVC `std::list` |
| **Completion status** | **Dual sealed MEGA-052** |
| **Dual verdict** | **accept-with-gaps** (A+B) |
| **Runtime Confirmed** | **No** (terminal false) |

## Purpose

```text
list* StdList_DefaultCtor_Inferred(list* this)
  this->_Myhead = StdList_AllocEmptySentinel_Inferred()  // 0x0040fb90
  this->_Mysize = 0
  return this
```

Empty circular list object constructor. Paired with:

| Role | VA | Dual name |
|---|---|---|
| Alloc sentinel | `0x0040fb90` | `StdList_AllocEmptySentinel_Inferred` |
| Destroy free head | `0x00403430` | `StdList_Destroy_FreeHead_Inferred` |
| Clear | `0x00404060` | (clear helper) |
| Copy ctor sibling | `0x00402410` | residual |

## Signature

```c
void* __fastcall StdList_DefaultCtor_Inferred(void* self);
// ECX=self, EAX=self, RET
```

## Naming

| Candidate | Decision |
|---|---|
| `StdList_DefaultCtor_Inferred` | **Accepted** — CF/ABI/layout sealed; product `T` open → `_Inferred` |
| `Named_CalleeOf_CVOGReaction_Dispatch_004023f0` | **Retired** — parent-seed plate only |
| Mission/reaction helper names | **Rejected** — generic STL leaf |

## Dual reviews

| Path | File | Verdict |
|---|---|---|
| A fidelity | `docs/reconstruction/reviews/A_aa_004023f0_StdList_DefaultCtor_Inferred.md` | **accept-with-gaps** |
| B adversarial | `docs/reconstruction/reviews/B_aa_004023f0_StdList_DefaultCtor_Inferred.md` | **accept-with-gaps** |

## Gaps

1. `list+0` residual (allocator / container_base).
2. Consuming element type `T` (site-specific).
3. Runtime / bit-exact / differential.

## AutoCore port

Port as ordinary empty linked-list construction (`new List<T>()` / clear init). **thiscall-style ECX this**, no stack args. Pair teardown with free-head destroy. Do not attach reaction-dispatch side effects.
