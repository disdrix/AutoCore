# Review A (reconstruction fidelity): `aa_0055efd0` PhysSim_PushBodyPair_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0055efd0` |
| **VA** | `0x0055efd0` |
| **Canonical name** | `PhysSim_PushBodyPair_Inferred` |
| **Ghidra name** | `FUN_0055efd0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual A/B) |
| **Counterpart** | `reviews/B_aa_0055efd0_PhysSim_PushBodyPair_Inferred.md` |
| **System** | `physics` (island / sim pair glue) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC **thiscall** helper on the **sim/world** object: append one **8-byte body pair** `(a, b)` to the growable pair vector at **`world+0x20`**.

Used when `Phys_RegisterAction` (and sibling host-link paths) discovers two related bodies whose host **group keys** (`body+0x44`) differ — the pair is queued for later island glue / flush (see parent dual residual; consumer `FUN_00561320` family).

Not an action-list insert (`006292a0`). Not host activate (`0055eb80`). Not pair consumption.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0055efd0_FUN_0055efd0.md` |
| Annotated | `docs/reconstruction/raw/aa_0055efd0_FUN_0055efd0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0055efd0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0055efd0_FUN_0055efd0.md` |
| Live decompile | Ghidra MCP `batch_decompile` / `decompile_function` @ `0x0055efd0` |
| Bytes | `read_memory` 80 B @ entry — grow + store; epilogue **`C2 08 00` ret 8** |
| Call-site ABI | `get_assembly_context` @ `0x0055feca` / `0x0055f24a` — `MOV ECX, world; PUSH b; PUSH a` |
| Parent dual | `A\|B_aa_0055fe50_Phys_RegisterAction` (cross-island residual) |
| Grow sibling | `FUN_005b3300` (explicit newCap, elemSize) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__thiscall` ECX = **world/sim**; 2 stack formals; **`ret 8`** | **Confirmed** | bytes `C2 08 00`; call sites `MOV ECX,EBP/EDI` |
| Header at `this+0x20`: `{void* data; int count; int capRaw}` | **Confirmed** | body loads `+0x20/+0x24/+0x28` |
| Element size **8** (two dwords) | **Confirmed** | grow call push `8`; stores `*8-8` / `*8-4` |
| Capacity mask `capRaw & 0x7fffffff` | **Confirmed** | asm `and eax, 0x7fffffff` |
| Grow when `count+1 > capacity` | **Confirmed** | |
| `newCap = max(capacity*2, count+1)` | **Confirmed** | double then clamp up to needed |
| Grow via `FUN_005b3300(hdr, newCap, 8)` | **Confirmed** | sole callee |
| Then `count = count+1`; store `(a,b)` at last slot | **Confirmed** | order: store a at `-8`, b at `-4` relative to `data + count*8` |
| Role = **pending body-pair queue** (cross-host / cross-island link) | **High** | sole semantic from RegisterAction + `0055f210` / `006292e0` |
| Product / PDB name | **Open** | working `_Inferred` |
| Consumer of the pair list (full English) | **Open** | flush path residual |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Load hdr `this+0x20`, count, cap | Yes |
| `need = count+1`; if need > cap → grow | Yes |
| `newCap = max(cap*2, need)` | Yes |
| `FUN_005b3300(hdr, newCap, 8)` | Yes |
| Publish count; write pair | Yes |
| `ret 8` | Yes (raw scaffold lacked explicit ABI note) |

### Recovered CF

```c
// void __thiscall PhysSim_PushBodyPair_Inferred(World *world, void *bodyA, void *bodyB)
// RET 8
void PhysSim_PushBodyPair_Inferred(void *world, void *bodyA, void *bodyB)
{
  int *hdr = (int *)((char *)world + 0x20);  // [0]=data, [1]=count, [2]=capRaw
  int need = hdr[1] + 1;
  int cap  = (int)((unsigned)hdr[2] & 0x7fffffff);
  if (cap < need) {
    int newCap = cap * 2;
    if (newCap <= need) newCap = need;
    FUN_005b3300(hdr, newCap, /*elemSize=*/8);
  }
  hdr[1] = need;
  void *data = *(void **)hdr;
  ((void **)data)[need * 2 - 2] = bodyA;  // data + need*8 - 8
  ((void **)data)[need * 2 - 1] = bodyB;  // data + need*8 - 4
}
```

---

## 5. Callers

| Caller | Site | Notes |
|---|---|---|
| `Phys_RegisterAction` `0x0055fe50` | `0x0055feca` | After first host; if next body host key `+0x44` differs → pair (firstBody, nextBody); **ECX=world** |
| `FUN_0055f210` | `0x0055f24a` | Host-link path; **ECX=world** |
| `FUN_006292e0` | `0x00629452` | Contact / pair examine path; gates on body flags `+0x40` |

**3 UNCONDITIONAL_CALL xrefs.** Parent dual residual closed for this leaf.

Also **inlined** same policy inside `FUN_00560f70` (pair writes to `param_1+0x20` without calling this VA).

---

## 6. Gaps

1. Product name for pair vector / API.
2. Exact English of `body+0x44` (island / sim-host group key) — structural sealed as compare key.
3. Pair-list consumer (`FUN_00561320` / island post-collide glue) not dualed here.
4. Runtime / bit-exact open.

**Verdict:** CF + ABI + layout + grow policy sealed. **accept-with-gaps.**
