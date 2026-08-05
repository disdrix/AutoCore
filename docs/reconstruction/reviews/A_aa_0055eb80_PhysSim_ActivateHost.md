# Review A (reconstruction fidelity): `aa_0055eb80` PhysSim_ActivateHost

| Field | Value |
|---|---|
| **Stable ID** | `aa_0055eb80` |
| **VA** | `0x0055eb80` |
| **Canonical name** | `PhysSim_ActivateHost` (inferred) |
| **Ghidra symbol** | `FUN_0055eb80` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual A/B) |
| **Counterpart** | `reviews/B_aa_0055eb80_PhysSim_ActivateHost.md` |
| **System** | `physics` (sim-context activate / ready) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

World / sim-context helper: **insert `host` into the active pointer array**, rewire free-list / index tables, mark host **ready** (`host+0x29 = 1`), clear host bookkeeping fields, and call post-activate `FUN_0062a6c0(world, host)`.

This is the **payload** of `CVOGPhysics_PrepareReady` when host is not yet ready and `host+0x24 ≠ -1`. Ready probe `FUN_005070b0` reads the same `host+0x29` flag.

Also called from other world list paths (`FUN_0055f210`, `FUN_0055fe50`, `FUN_00560a30`, `FUN_006292e0`) — not exclusive to PrepareReady.

---

## 2. Inspected artifacts

| Artifact | Path | This pass |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_0055eb80_FUN_0055eb80.md` | ≡ live decompile |
| Annotated | `docs/reconstruction/raw/aa_0055eb80_FUN_0055eb80.annotated.md` | Scaffold |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0055eb80.cpp` | CF ≡ raw |
| Named alias | `Named_CalleeOf_Named_CalleeOf_CVOGReaction_TeleportTarget_0055eb80.cpp` | Prior scaffold |
| Function record | `docs/reconstruction/functions/aa_0055eb80_FUN_0055eb80.md` | Scaffold |
| Live decompile | Ghidra MCP `0x0055eb80` | **≡ raw** |
| Live `read_memory` | entry grow + stores | `+0x29=1`, list `+8/+0xc` sealed |
| Caller ABI | `0x005070d0` dual + bytes | `push host; ECX=world` |
| Parent dual | `reviews/A_aa_005070d0_CVOGPhysics_PrepareReady.md` | Interface sealed |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `thiscall` ECX=world; stack arg=host; `ret 4` | **High** | PrepareReady asm + other callers |
| Grow active array at `world+8` when `count(+0xc) == capacity(+0x10)&0x7fffffff` | **High** | `FUN_005b3370((int*)(world+8), 4)` |
| Push host: `array[count]=host; count++` | **High** | Decompile |
| Free-list shuffle via `host+0x24` index and `world+0x14/+0x18` | **High** (CF) / **Probable** (English) | Swap last free into hole |
| `host+0x24 = count-1` (new active index) | **High** | Store after push |
| **`*(u8*)(host+0x29) = 1`** (ready flag) | **High** | Core prepare side-effect |
| Clear `host+0x34`, `host+0x38` to 0 | **High** | Two dword stores |
| `FUN_0062a6c0(world, host)` then `host+0x30 = 0` | **High** | Order sealed; callee body open |
| PrepareReady gates: only if ready==0 and index≠−1 | **High** | Parent dual |
| Product English name | **Probable** | Role sealed |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| If full → grow by 4 (`FUN_005b3370`) | Yes |
| Append host to `*(world+8)` at index `*(world+0xc)` | Yes |
| Increment count `+0xc` | Yes |
| Free-list / index table rewire (`+0x14`, `+0x18`, `host+0x24`) | Yes |
| Dec free count `+0x18` | Yes |
| Set `host+0x24 = count-1` | Yes |
| Set `host+0x29 = 1` | Yes |
| Zero `+0x34/+0x38`; call `0062a6c0`; zero `+0x30` | Yes |
| No invent remove-from-0x108 list | Yes (sibling `0x55e490`) |

### Authoritative contract

```c
// PhysSim_ActivateHost (Probable)
// thiscall ECX = sim/world*; stack: host*; RET 4
void __thiscall PhysSim_ActivateHost(void *world, void *host)
{
  int *vec = (int*)((char*)world + 8);   // { ptr, count, cap... }
  if ((uint)vec[1] == ((uint)vec[2] & 0x7fffffff))
    FUN_005b3370(vec, 4);                // grow capacity by 4 slots

  void **arr = *(void***)vec;
  int count = vec[1];
  arr[count] = host;
  vec[1] = count + 1;

  // free-list table at world+0x14, free count world+0x18
  // move last free entry into host's old free-slot index (host+0x24)
  // patch moved entry's +0x24; free_count--
  // host+0x24 = new active index (count)

  *(unsigned char*)((char*)host + 0x29) = 1;   // READY
  *(int*)((char*)host + 0x34) = 0;
  *(int*)((char*)host + 0x38) = 0;
  FUN_0062a6c0(world, host);
  *(unsigned char*)((char*)host + 0x30) = 0;
}
```

### PrepareReady call site (sealed)

```text
005070e0  mov  eax, [esi+0x44]      ; host
005070e3  cmp  byte ptr [eax+0x29], 0
005070e7  jnz  ret                  ; already ready
005070e9  cmp  dword ptr [eax+0x24], -1
005070ed  jz   ret                  ; invalid index
005070ef  mov  ecx, [esi+8]         ; world
005070f2  push eax                  ; host
005070f3  call FUN_0055eb80
```

---

## 5. Layout

### World / sim (`this`)

| Offset | Role |
|-------:|------|
| `+0x08` | active ptr array base |
| `+0x0c` | active count |
| `+0x10` | capacity (low 31 bits; high bit flag mask `0x7fffffff`) |
| `+0x14` | free-list / index table base |
| `+0x18` | free-list count |

### Host (`arg`, also `phys+0x44`)

| Offset | Role |
|-------:|------|
| `+0x24` | int index (−1 = not eligible for activate in PrepareReady) |
| `+0x29` | u8 ready flag (probe reads this) |
| `+0x30` | u8 cleared post-activate |
| `+0x34` / `+0x38` | cleared dwords |

---

## 6. Callers (live xrefs)

| Function | Role |
|---|---|
| `FUN_005070d0` PrepareReady | Write-enable path |
| `FUN_0055f210`, `FUN_0055fe50`, `FUN_00560a30` | Related world list ops |
| `FUN_006292e0` | World / sim path |

---

## 7. Gaps / open

1. Exact types of world and host (Havok action? custom island host?).
2. Full free-list algorithm edge cases (empty free list, corrupt index).
3. Body of `FUN_0062a6c0` (post-activate notify).
4. Grow helper `FUN_005b3370` dual.
5. Product / PDB name; runtime double-activate policy if gate bypassed.

**Verdict:** **accept-with-gaps** — **activate CF + ready flag + list grow/push + PrepareReady ABI + multi-caller surface** sealed; deep free-list/types/runtime open.
