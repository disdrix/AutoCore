# Review A (reconstruction fidelity): `aa_00970cf0` AssPreloader_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00970cf0` |
| **VA** | `0x00970cf0`–`0x00970e4c` exclusive (**348 B**) |
| **Canonical name** | `AssPreloader_Ctor_Inferred` |
| **Ghidra name** | `FUN_00970cf0` |
| **Prior scaffold** | `FUN_00970cf0` / `Named_CalleeOf_*Client_InitI_00970cf0` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY dual W37-W) |
| **Counterpart** | `reviews/B_aa_00970cf0_AssPreloader_Ctor_Inferred.md` |
| **System** | assets / AssPreloader construction |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` + callers/xrefs/callees + parent ensure bytes. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Placement constructor for the **AssPreloader** object allocated by sole parent ensure (`operator_new(0x114)`):

1. Install vtbl `PTR_FUN_00aa9a94` (vtbl[0] = scalar-deleting dtor `FUN_00481270`).
2. `CreateEventA(NULL, FALSE, FALSE, NULL)` → handle at `+0x04`.
3. Allocate map head via `StdTree_AllocNode_0x1c` → `+0x14` (isnil/circular wiring; size `@+0x18`).
4. Initialize **four** GuardedVector+CS banks (seed ring header used as container `@+0xAC`).
5. Allocate second tree head via `RbTree_AllocEmptyNode` → `+0xE0`.
6. Store host back-pointer at `+0x110` (= ctor param_2).

**Not** a method on an already-live preloader, not ensure/seed logic (those live in parent `0x0075d3c0`), not worker/enqueue.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x00970cf0` (2026-08-04) ≡ raw 2026-07-23 |
| Bytes | `read_memory` 512 B — full **348 B** body; SEH `LAB_009accf1`; **`C2 08 00`** |
| Parent | ensure dual W33-O + live decompile + call-site bytes `push host; push mem; call` |
| Callees | `CreateEventA` IAT `[0x009c61fc]`; `InitializeCriticalSection` IAT `[0x009c61ec]`; `FUN_005ae2b0`; `FUN_00439770` |
| Family | retire/enqueue/worker duals (cache `@+0x110`, map `@+0x10`, ring `@+0xAC`) |
| Vtbl | `read_memory` `0x00aa9a94` → `0x00481270` scalar-deleting dtor |
| Raw / annotated / clean | `aa_00970cf0_*`, named + scaffold cleans |
| Callers | `get_function_callers` / `get_xrefs_to` → `FUN_0075d3c0` @ `0x0075d405` only |

**Not performed:** Launcher, runtime, ledgers, `disassemble_bytes`.

---

## 3. Signature (sealed)

```c
// stack (self*, host*); RET 0x08; returns self* in EAX
AssPreloader* AssPreloader_Ctor_Inferred(AssPreloader* self, void* host);
```

| Formal | Source | Conf |
|---|---|---|
| self* | stack0 (`mov esi,[esp+0x1C]` after prolog) | **Confirmed** |
| host* | stack1 → stored `@+0x110` | **Confirmed** |
| RET 8 | `C2 08 00` | **Confirmed** |
| return self* | `mov eax,esi` before epilogue | **Confirmed** |
| Object size 0x114 | parent `operator_new(0x114)` | **Confirmed** |

Parent call site (ensure bytes): `push ebp` (host) / `push eax` (mem) / `call FUN_00970cf0`.

---

## 4. Control flow / layout: clean ≡ raw ≡ live

| Stage | Match | Conf |
|---|---|---|
| SEH install `LAB_009accf1` | **Yes** | **Confirmed** |
| vtbl `PTR_FUN_00aa9a94` | **Yes** | **Confirmed** |
| CreateEventA → +0x04 | **Yes** | **Confirmed** |
| Tree head FUN_005ae2b0 → +0x14 + isnil wiring | **Yes** | **Confirmed** |
| 4× zero triad + InitializeCriticalSection + flag=1 | **Yes** | **Confirmed** |
| FUN_00439770 → +0xE0 + isnil wiring | **Yes** | **Confirmed** |
| host → +0x110; zero pad +0xE8..+0x10C | **Yes** | **Confirmed** |
| ret 8 / return self | **Yes** | **Confirmed** |

### GuardedVector seed ring (cross-dual)

| Field | Offset from self | Notes |
|---|---|---|
| GuardedVector `this` | `+0xAC` | ensure seeds here (W33-O) |
| pages / capacity / begin / size | `+0xB0`..`+0xBC` | zeroed in ctor |
| CRITICAL_SECTION | `+0xC0` | = header+0x14 |
| lockEnable | `+0xD8` | = header+0x2c; set 1 |

Matches W32-N `GuardedVector_PushBackLocked_Stride2_U32U8` header layout.

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Placement ctor / size 0x114 | **Confirmed** | parent ensure |
| Two stack formals RET 8 | **Confirmed** | bytes + parent push order |
| Event + 4 CS + two tree heads | **Confirmed** | decompile + callees |
| host@+0x110 | **Confirmed** | store + family duals |
| Seed ring header @+0xAC | **High** | ensure bytes + GuardedVector dual |
| Roles of banks A–C | **Probable** | zeroed + CS; product roles open |
| Product class English | **Open** | `_Inferred` |
| SEH unwind / full dtor plate | **Open** | not owned |
| Runtime / bit-exact | **Open** | — |

---

## 6. Gaps / open

1. Product class/method English (AssPreloader name is family-structural, not RTTI-sealed on this VA).  
2. Exact product roles of GuardedVector banks A–C vs D.  
3. Full SEH state machine / exception-safe partial-construction teardown.  
4. Second tree (`+0xE0`) element/product type residual.  
5. Runtime / bit-exact.

---

## 7. Verdict

**accept-with-gaps** — ctor ABI/size/vtbl/event/trees/CS banks/host@+0x110 sealed; product English + bank roles + SEH residual open.
