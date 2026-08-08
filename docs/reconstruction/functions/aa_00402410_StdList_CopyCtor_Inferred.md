# Function record: StdList_CopyCtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00402410` |
| **Canonical name** | `StdList_CopyCtor_Inferred` |
| **Ghidra name** | `FUN_00402410` |
| **Address** | `0x00402410`–`0x00402495` inclusive (**134 B** / `0x86`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | shared MSVC `std::list` |
| **Completion status** | **Dual sealed R10-019** |
| **Dual verdict** | **accept-with-gaps** (A+B) |
| **Runtime Confirmed** | **No** (terminal false) |

## Purpose

```text
list* StdList_CopyCtor_Inferred(list* dest, list* src)  // stdcall RET 8
  dest._Myhead = StdList_AllocEmptySentinel_Inferred()  // 0x0040fb90
  dest._Mysize = 0
  range-insert [src.begin(), src.end()) before dest.end() via FUN_00404490
  return dest
```

Copy-construct helper for MSVC circular list objects. Paired with:

| Role | VA | Dual name |
|---|---|---|
| Alloc sentinel | `0x0040fb90` | `StdList_AllocEmptySentinel_Inferred` |
| Empty default ctor sibling | `0x004023f0` | `StdList_DefaultCtor_Inferred` |
| Destroy free head | `0x00403430` | `StdList_Destroy_FreeHead_Inferred` |
| Range insert chain | `0x00404490` / `0x00404560` / `0x004040f0` | residual |

## Signature

```c
void* __stdcall StdList_CopyCtor_Inferred(void* dest, void* src);
// [EBP+8]=dest, [EBP+0xC]=src; EAX=dest; RET 0x8
// NOTE: not ECX-thiscall (differs from StdList_DefaultCtor_Inferred)
```

## Naming

| Candidate | Decision |
|---|---|
| `StdList_CopyCtor_Inferred` | **Accepted** — CF/ABI/layout sealed; product `T` open → `_Inferred` |
| Mission/reaction helper names | **Rejected** — generic STL leaf |
| `StdList_DefaultCtor_*` | **Rejected** — this unit inserts range after empty init |
| Assign-in-place / operator= | **Rejected** — always new sentinel into `dest` |

## Dual reviews

| Path | File | Verdict |
|---|---|---|
| A fidelity | `docs/reconstruction/reviews/A_aa_00402410_StdList_CopyCtor_Inferred.md` | **accept-with-gaps** |
| B adversarial | `docs/reconstruction/reviews/B_aa_00402410_StdList_CopyCtor_Inferred.md` | **accept-with-gaps** |

## Gaps

1. Element type `T` (site-specific; residual insert chain).
2. `list+0` residual (allocator / container_base).
3. Insert helpers `00404490`/`00404560`/`004040f0` not dualed here.
4. Runtime / bit-exact / differential.
5. MSVC decoration for stdcall 2-arg vs textbook thiscall copy-ctor.

## AutoCore port

Port as list copy-construction into a fresh object (`new List<T>(src)` / construct-into-dest). **Stdcall two stack args**, return dest. Pair with sentinel alloc + free-head destroy. Do **not** use ECX thiscall like the empty default ctor sibling. Do not attach mission/reaction side effects from sole caller `FUN_00955010`.
