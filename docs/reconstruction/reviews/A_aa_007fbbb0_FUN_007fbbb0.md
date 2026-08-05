# Review A (reconstruction fidelity): `aa_007fbbb0` FUN_007fbbb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fbbb0` |
| **VA** | `0x007fbbb0` |
| **Body** | `0x007fbbb0`–`0x007fbc6a` |
| **Canonical name** | `FUN_007fbbb0` (leave-FUN; human alias below) |
| **Human alias** | `Named_CalleeOf_Client_SendInventoryGrab_FromGrid_007fbbb0` / Grab-path **held-object UI clear** helper |
| **Review date** | `2026-07-29` (wave8 OWN-ONLY dual — Grab path) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw/annotated) |
| **Counterpart** | `reviews/B_aa_007fbbb0_FUN_007fbbb0.md` |
| **Live re-decompile** | Ghidra MCP `force_decompile` + `decompile_function` 2026-07-29 — body **≡** raw capture |
| **read_memory** | Body bytes at entry (187-byte payload + INT3 pad); offsets `0x113c`/`0xf40`/`0xd0`/`0x2b0`/`0xb0`/`0x1c8`/`0x3c0`/`0x514`→`0x498`/`0x518`→`0x49c` present |
| **P-code** | basic-iter: ESI (`register:0x18`) + `0x113c` / `0xf40` loads; all work is **CALLIND** (no named direct callees) |
| **System tag** | `inventory-transfer` (Grab pre-helper) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Local UI / client-host bookkeeping before InventoryGrab senders run.** Not a packer, not a sector send.

On the client host object in **ESI**:

1. If `*(host+0x113c)` (held / cursor inventory object*) is non-null
2. Call that object’s vfunc **`vtbl+0xd0`** → `char`/`bool`
3. If non-zero **and** `*(held+0x2b0) != 0`
4. Then:
   - UI root `**(host+0xf40)` **`vtbl+0xb0(held)`** — detach / notify with held object
   - held **`vtbl+4(0)`** — scalar release / destroy with flag 0
   - UI root **`vtbl+0x1c8(0)`** then **`vtbl+0x3c0(0)`** — zero-arg UI state clears
   - If `*(ui+0x514) > 0`: copy `ui+0x514` → `ui+0x498`
   - If `*(ui+0x518) > 0`: copy `ui+0x518` → `ui+0x49c`
5. Return void

Grab callers (`Client_SendInventoryGrab_FromGrid`, `Client_SendInventoryGrab_Hardpoint`, others) invoke this **before** busy-gate / packet pack. No-op when no held object or gate fails.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live Ghidra decompile | `FUN_007fbbb0` @ `0x007fbbb0` ≡ frozen raw |
| Raw | `docs/reconstruction/raw/aa_007fbbb0_FUN_007fbbb0.md` |
| Annotated | `docs/reconstruction/raw/aa_007fbbb0_FUN_007fbbb0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_007fbbb0.cpp` |
| Named clean alias | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Client_SendInventoryGrab_FromGrid_007fbbb0.cpp` |
| Function record | `docs/reconstruction/functions/aa_007fbbb0_FUN_007fbbb0.md` |
| Parent duals (context only) | `A/B_aa_00860e20_Client_SendInventoryGrab_FromGrid`, `A/B_aa_00862d90_…Hardpoint` |
| Xrefs | 11 UNCONDITIONAL_CALL sites (see §5) |
| Assembly context | FromGrid / Hardpoint / `FUN_007ff3d0` call sites |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF from decompile ≡ raw ≡ clean | **Confirmed** | force re-decompile 2026-07-29 |
| `unaff_ESI` = client host layout (`+0x113c`, `+0xf40`) | **High** | P-code ESI; call sites `MOV ESI,0xd1a840` or `MOV ESI,EBX` with same offsets |
| Host often `DAT_00d1a840` at Grab call sites | **High** | asm at `0x00860e61`, `0x00862d94` |
| Gate: held ptr + vtbl+0xd0 + field `+0x2b0` | **Confirmed** | CF + memory offsets |
| Four CALLIND side effects then two conditional field copies | **Confirmed** | order sealed |
| No direct named callees (leaf vs symbol table) | **Confirmed** | analyze_function_complete callees=[] |
| Void return (no EAX contract) | **High** | RET after pure side effects; return_type warning on undefined is noise |
| Semantic: “clear held UI item before grab” | **Probable** | CF + Grab placement; no strings in body |
| Exact meaning of vtbl slots / `0x514`/`0x518` dims | **Tentative** | CF sealed; labels open |
| Does not pack `0x2034` / does not set busy flags | **Confirmed** | no immediates / no DAT writes in body |

---

## 4. Control flow: clean ≡ raw

| Stage | Raw / live | Clean | Match |
|---|---|---|---|
| Null held `*(ESI+0x113c)` → ret | Yes | Yes | **Yes** |
| `held.vtbl+0xd0()` → false → ret | Yes | Yes | **Yes** |
| `*(held+0x2b0)==0` → ret | Yes | Yes | **Yes** |
| UI `vtbl+0xb0(held)` | Yes | Yes | **Yes** |
| `held.vtbl+4(0)` | Yes | Yes | **Yes** |
| UI `vtbl+0x1c8(0)` | Yes | Yes | **Yes** |
| UI `vtbl+0x3c0(0)` | Yes | Yes | **Yes** |
| Copy `0x514→0x498` if >0 | Yes | Yes | **Yes** |
| Copy `0x518→0x49c` if >0 | Yes | Yes | **Yes** |

No invented clamps. Clean may model ESI as an explicit host parameter for portability — honest expansion of decompiler `unaff_ESI` (same pattern as FromGrid EDI).

### Authoritative body (live ≡ raw)

```c
void FUN_007fbbb0(void)
{
  int iVar1;
  char cVar2;
  int unaff_ESI;  // client host* (register ESI)

  if (*(int *)(unaff_ESI + 0x113c) != 0) {
    cVar2 = (**(code **)(**(int **)(unaff_ESI + 0x113c) + 0xd0))();
    if ((cVar2 != '\0') && (*(int *)(*(int *)(unaff_ESI + 0x113c) + 0x2b0) != 0)) {
      (**(code **)(*(int *)**(undefined4 **)(unaff_ESI + 0xf40) + 0xb0))
                (*(int *)(unaff_ESI + 0x113c));
      (**(code **)(**(int **)(unaff_ESI + 0x113c) + 4))(0);
      (**(code **)(*(int *)**(undefined4 **)(unaff_ESI + 0xf40) + 0x1c8))(0);
      (**(code **)(*(int *)**(undefined4 **)(unaff_ESI + 0xf40) + 0x3c0))(0);
      if (0 < *(int *)(**(int **)(unaff_ESI + 0xf40) + 0x514)) {
        iVar1 = **(int **)(unaff_ESI + 0xf40);
        *(undefined4 *)(iVar1 + 0x498) = *(undefined4 *)(iVar1 + 0x514);
      }
      if (0 < *(int *)(**(int **)(unaff_ESI + 0xf40) + 0x518)) {
        iVar1 = **(int **)(unaff_ESI + 0xf40);
        *(undefined4 *)(iVar1 + 0x49c) = *(undefined4 *)(iVar1 + 0x518);
      }
    }
  }
  return;
}
```

---

## 5. Callers (xrefs — names as of DB)

| Site | Parent (DB) | ESI setup (asm context) |
|---|---|---|
| `0x00860e66` | `Client_SendInventoryGrab_FromGrid` | `MOV ESI,0xd1a840` then CALL |
| `0x00862d99` | `Client_SendInventoryGrab_Hardpoint` | `MOV ESI,0xd1a840` then CALL |
| `0x007ff57b` | `FUN_007ff3d0` | `MOV ESI,EBX` (host in EBX; later uses `EBX+0xf40`/`0x113c`) |
| `0x00802243` | `FUN_00802170` | context near other client UI calls |
| `0x00861b61` | `FUN_00861680` | (Grab/UI neighborhood) |
| `0x009452ff` | `FUN_00944d50` | |
| `0x008c3ccc` | `FUN_008c3ca0` | |
| `0x009257cb` | *(unnamed in complete summary)* | |
| `0x0083e5eb` | *(unnamed)* | |
| `0x0083e6de` | *(unnamed)* | |
| `0x008c2c07` | *(unnamed)* | |

**11 xrefs total.** Fan-in beyond Grab-only: helper is a **shared client held-object clearer**, not exclusive to FromGrid.

### Indirection map (own body only)

| Slot | Shape | Role (CF) |
|---|---|---|
| `host+0x113c` | `object*` | held / cursor inventory object |
| `held.vtbl+0xd0` | `() → char` | gate predicate |
| `held+0x2b0` | `ptr/nonzero` | second gate (sub-object present) |
| `host+0xf40` | `T**` → object with vtbl | UI / inventory root |
| `ui.vtbl+0xb0` | `(held*)` | detach/notify |
| `held.vtbl+4` | `(0)` | release |
| `ui.vtbl+0x1c8` | `(0)` | clear A |
| `ui.vtbl+0x3c0` | `(0)` | clear B |
| `ui+0x514` → `ui+0x498` | `i32` copy if >0 | restore/sync field pair |
| `ui+0x518` → `ui+0x49c` | `i32` copy if >0 | restore/sync field pair |

---

## 6. Gaps / open

1. Semantic names for vtbl `+0xd0`, `+0xb0`, `+0x1c8`, `+0x3c0`, `+4` (need target resolve per concrete vtable — **out of own-VA scope**).
2. Meaning of field pairs `0x514/0x498` and `0x518/0x49c` (grid size? scroll? selection rect?).
3. Whether `held.vtbl+4(0)` frees and who nulls `host+0x113c` (not written in this body).
4. Full identity of non-Grab parents (rename deferred).
5. Runtime / CE capture of held-clear on grab click.
6. Official human rename still provisional (parent-seed alias only).

**Verdict:** **accept-with-gaps.** Mechanical CF, ESI host ABI, offset map, and Grab placement sealed. Do not claim packet work or busy flags. Vtbl/field labels remain Tentative.
