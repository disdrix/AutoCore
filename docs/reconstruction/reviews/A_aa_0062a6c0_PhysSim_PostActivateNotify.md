# Review A (reconstruction fidelity): `aa_0062a6c0` PhysSim_PostActivateNotify

| Field | Value |
|---|---|
| **Stable ID** | `aa_0062a6c0` |
| **VA** | `0x0062a6c0` |
| **Canonical name** | `PhysSim_PostActivateNotify` (inferred) |
| **Ghidra symbol** | `FUN_0062a6c0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual A/B) |
| **Counterpart** | `reviews/B_aa_0062a6c0_PhysSim_PostActivateNotify.md` |
| **System** | `physics` (sim activate / teleport rewire) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Post-activate / attachment rewire invoked as the **tail** of `PhysSim_ActivateHost` (`0x0055eb80`):

```text
host.ready (+0x29) = 1
clear host +0x34/+0x38
FUN_0062a6c0(world, host)     // this unit
host.byte_30 = 0
```

Also on the **TeleportTarget** callee chain (scaffold name). Body:

1. **Reverse-walk** `world` list at `+0x78` (ptrs) / count `+0x7c`; for each non-null entry, **`vtbl+0x04`(host)**.
2. **`FUN_005fff20(world)`** (world-side reset / flush — body not dualed here).
3. For each entry in **host** list `host+0x3c` / count `host+0x40`:
   - Reverse-walk sublist at entry `+0x70` / count `+0x74`; non-null → **`vtbl+0x08`(entry)**.
   - Second reverse pass: **compact nulls** (swap-remove: dec count, shift tail down).

Net: notify world listeners of newly active host, flush world helper, then notify/compact host-side attachment lists.

---

## 2. Inspected artifacts

| Artifact | Path | This pass |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_0062a6c0_FUN_0062a6c0.md` | ≡ live |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0062a6c0.cpp` | CF ≡ raw |
| Live decompile | Ghidra MCP `0x0062a6c0` | **≡ raw** |
| Live `read_memory` | entry | reverse loops / `+0x78/+0x7c` sealed |
| Parent dual | `reviews/A_aa_0055eb80_PhysSim_ActivateHost.md` | Call order sealed |
| Sole Ghidra caller list | `FUN_0055eb80` | ActivateHost |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| ABI: stack `world`, `host` (not thiscall in decompiler form) | **High** | Asm loads both from stack; ActivateHost `push host; ECX=world` may still be thiscall — decompiler shows cdecl-like; **ActivateHost dual says `FUN_0062a6c0(world, host)`** |
| World list `+0x78` / count `+0x7c`, reverse, vtbl `+4` | **High** | Decompile + bytes |
| Null entries skipped | **High** | |
| `FUN_005fff20` after first loop | **High** | Single callee besides vcalls |
| Host list `+0x3c` / `+0x40` | **High** | |
| Per-entry sublist `+0x70` / `+0x74`, vtbl `+8` | **High** | |
| Compact nulls after notify (order: notify all, then compact) | **High** | Two separate reverse while loops |
| Does not set ready flag (parent does) | **High** | No `+0x29` store here |
| English name | **Probable** | Role from parent dual |
| Semantic names of vtbl `+4` / `+8` | **Tentative** | “on host activated” / “on parent activated” style |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Reverse world listeners `+0x78` → vcall `+4(host)` | Yes |
| `FUN_005fff20` | Yes |
| For i in `[0, host.count+0x40)` | Yes |
| Reverse entry sublist → vcall `+8(entry)` | Yes |
| Reverse compact nulls in same sublist | Yes |
| No invent ready-bit | Yes |

### Contract sketch

```c
void PhysSim_PostActivateNotify(void *world, void *host)
{
  // world listeners
  for (int i = *(int*)(world+0x7c) - 1; i >= 0; --i) {
    int *obj = *(int**)(*(int*)(world+0x78) + i*4);
    if (obj) (*obj)[1](host);           // vtbl+4
  }
  FUN_005fff20(world);

  int n = *(int*)(host+0x40);
  for (int i = 0; i < n; ++i) {
    int *entry = *(int**)(*(int*)(host+0x3c) + i*4);
    int *list = (int*)(entry + 0x70/4); // +0x70 ptr, +0x74 count
    // notify reverse
    for (int j = entry[0x74/4]-1; j >= 0; --j) {
      int *c = *(int**)(*list + j*4);
      if (c) (*c)[2](entry);            // vtbl+8
    }
    // compact nulls reverse
    for (int j = entry[0x74/4]-1; j >= 0; --j) {
      if (*(int*)(*list + j*4) == 0) {
        // swap-remove: count--, shift [j+1..] down
      }
    }
  }
}
```

---

## 5. Callers / callees

**Callees:** `FUN_005fff20`, virtual `+4` / `+8`.

**Callers:** `FUN_0055eb80` (`PhysSim_ActivateHost`) — primary production site (Ghidra callers list). Teleport scaffold naming indicates ActivateHost is also used from teleport paths.

---

## 6. Gaps / open

1. Body dual of `FUN_005fff20`.
2. Exact interface of listener vtbl slots `+4` / `+8`.
3. Confirm cdecl vs thiscall ABI at call sites beyond ActivateHost.
4. Runtime not run.

**Verdict:** **accept-with-gaps** — list offsets, reverse notify, compact, and parent call order sealed; listener method names open.
