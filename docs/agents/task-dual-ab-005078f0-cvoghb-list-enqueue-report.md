# Dual A/B report — `aa_005078f0` CVOGHBList_Enqueue

**Date:** 2026-07-29  
**Scope:** OWN ONLY VA `0x005078f0` (`aa_005078f0` / `CVOGHBList_Enqueue`). Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG.  
**Ghidra:** `decompile_function` @ `0x005078f0`, `0x005b3370` (grow), `0x00507d10` (ctor layout); `get_function_by_address`; `get_function_xrefs` / `get_function_callers`. No `disassemble_bytes`. No Launcher.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005078f0` CVOGHBList_Enqueue | **accept** — pending CS append, HRESULT, grow double sealed |

Path A (fidelity): **accept**  
Path B (adversarial): **accept** on CF; grow-policy gap closed

---

## Sealed facts

1. **ABI:** MSVC **`__thiscall`**. `this` = list; stack/`edx` path carries **`CVOGHBBase* pAction`**. Returns **`uint`** in EAX: **`0`** success, **`0x80070057`** (`E_INVALIDARG`) if `pAction == null`. Body `0x005078f0`–`0x00507946`.

2. **Null gate before lock:** null action returns **without** entering the critical section.

3. **Critical section:** `EnterCriticalSection` / `LeaveCriticalSection` on **`this+0x04`**. Ctor initializes that CS with spin count **4000**.

4. **Pending-only append** (not active):
   - Buffer: **`this+0x28`** (`CVOGHBBase**`)
   - Count: **`this+0x2c`** (post-increment after store)
   - Capacity raw: **`this+0x30`**, usable = **`& 0x7fffffff`**
   - Active array is **`+0x1c/+0x20/+0x24`** — **not** written here; **`CVOGHBList_Tick`** promotes pending → active then TryFires.

5. **Grow gate:** when `pendingCount == (pendingCapRaw & 0x7fffffff)`, call **`FUN_005b3370(this+0x28, 4)`** (element size **4** = pointer).

6. **Grow policy (`0x005b3370`) sealed:** treats triple `{buf, count, cap}` at the passed slot; **`newCap = (count == 0) ? 1 : count * 2`**; allocate via `DAT_00b05060` vtbl+0x10 with tag **`0x12`**; memcpy `count * elementSize` bytes; free old buffer only if **`(int)oldCap >= 0`**; write new `buf` and `cap` (**count unchanged**). Ctor seeds cap raw **`0x80000000`** so first grow does not free.

7. **Start ≠ Enqueue:** this unit does not call OnStart / clear dormant. Arming path is typically **construct → Start → Enqueue**; Tick alone cannot see an un-enqueued HB.

8. **Call-site list pointer pattern:** many callers pass **map/world `+0xe4ec`** as the list (regen, cast-again, status FX, patrol, vehicle enter, etc.). High fan-in (50+ xrefs).

9. **Clean ≡ raw CF.** Prior raw plate “Returns: void” is documentation error; clean already returns HRESULT.

---

## Gaps

1. Product/RTTI name for grow helper `FUN_005b3370` and allocator object `DAT_00b05060`.  
2. Exhaustive audit of Start-without-Enqueue / Enqueue-without-Start call sites (caller residual).  
3. Whether any production path ignores `0x80070057` and whether null is ever intentionally passed.  
4. Runtime / CE / bit-exact verification not run this pass.  
5. Full `CRITICAL_SECTION` size / fields between `+0x04` and active buffer `+0x1c` not re-mapped here (Windows CS layout assumed).

---

## Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_005078f0_CVOGHBList_Enqueue.md` |
| Review B | `docs/reconstruction/reviews/B_aa_005078f0_CVOGHBList_Enqueue.md` |
| Function record | `docs/reconstruction/functions/aa_005078f0_CVOGHBList_Enqueue.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBList_Enqueue.cpp` |
| Raw | `docs/reconstruction/raw/aa_005078f0_CVOGHBList_Enqueue.md` |
| Annotated | `docs/reconstruction/raw/aa_005078f0_CVOGHBList_Enqueue.annotated.md` |
| This report | `docs/agents/task-dual-ab-005078f0-cvoghb-list-enqueue-report.md` |

Related (not owned this task):  
`CVOGHBList_Tick` `aa_00507950`, `CVOGHBList_ctor` `aa_00507d10`, `CVOGHBBase_Start` `aa_005081c0`.

---

## AutoCore impact

- Client timed actions (combat regen pulse, cast-again CD HB, status FX, mission patrol init, first-time tips) **enqueue pending** then rely on **Tick promote** — do not model Enqueue as immediate fire.
- Server ports of heartbeat lists need the same **pending + CS + promote** contract if mirroring client timing, or an explicit design decision to skip the two-phase queue.
- Null enqueue returns **`E_INVALIDARG`**; implementers should not treat Enqueue as `void`.
- Capacity growth is **double (min 1)**, pointer elements — not a fixed ring; unbounded enqueue under load will grow heap.
