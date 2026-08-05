# Review A (reconstruction fidelity): `aa_00541a80` Client_EnsureTypeDefHashReady_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00541a80` |
| **VA** | `0x00541a80` |
| **Canonical name** | `Client_EnsureTypeDefHashReady_Inferred` |
| **Ghidra symbol** | `FUN_00541a80` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual A/B) |
| **Counterpart** | `reviews/B_aa_00541a80_Client_EnsureTypeDefHashReady_Inferred.md` |
| **System** | client type-def / SpecialFX suppress hash (CNDHash) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Tiny ensure+get helper:** if the **CNDHash (or table object) at `host+0xF1C` reports count/size `< 1`**, **reload/rebuild** via **`FUN_00541950`**, then **return `*(host+0xF1C)`**.

Live body:

```c
undefined4 __fastcall FUN_00541a80(int host)  // ECX = host
{
  if (*(int *)(*(int *)(host + 0xf1c) + 0xc) < 1) {
    FUN_00541950();  // reload — uses same host (reg this)
  }
  return *(undefined4 *)(host + 0xf1c);
}
```

### Reload sibling (`FUN_00541950`) — sealed role

- Free prior buffer at **`host+0xF20`**.
- Vcall **`[*(host+0xF1C)]+4`** (clear/reset table object).
- Load records via **`FUN_007dbce0`** into temp; stride **`0x154`**.
- Alloc `count * 0x154` into **`host+0xF20`**, copy, then per-record **`FUN_00545a90`** setup.
- On load error path logs **`"VOG_DEBUG_STOP"`**.

### Call-site role

`FUN_004b7e50` (SpecialFX play):

```text
hash = FUN_00541a80();
def  = CNDHash_LookupByKey(hash, typeKeyFromTarget);
// if def present under suppress conditions → early return (no play)
```

Also called from `Client_OnServerConnectionTerminated` and many UI/world sites (20+ callers) — shared **type→def** map accessor.

Host `this` is typically a **process singleton** (callers often appear 0-arg; ECX preloaded).

---

## 2. Inspected artifacts

| Artifact | Path / source | This pass |
|---|---|---|
| Raw / annotated / clean | `aa_00541a80_*` | ≡ live |
| Live decompile | `0x00541a80`, `0x00541950` | sealed CF |
| Parent dual | `A_aa_004b7e50` | type→def suppress gate |
| Callers | Ghidra list incl. `004b7e50`, `Client_OnServerConnectionTerminated` | |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Returns pointer at `host+0xF1C` | **High** | |
| Gate: `*(hash+0xC) < 1` → reload | **High** | empty → rebuild |
| Reload = `FUN_00541950` | **High** | |
| Used as `CNDHash_LookupByKey` first arg | **High** | `004b7e50` |
| Record stride 0x154 on reload buffer `+0xF20` | **High** | `00541950` |
| Host is global client/game singleton | **High** (pattern) | many 0-arg sites |
| English / product name | **Probable** | |
| Exact type of object at `+0xF1C` beyond CNDHash API | **Medium** | vcall +4 on reload |
| Whether `+0xC` is always “count” | **High** (CNDHash family) | |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Load `hash = host+0xF1C` | Yes |
| if `hash+0xC < 1` → `FUN_00541950` | Yes |
| return `host+0xF1C` | Yes |

```text
EnsureTypeDefHashReady(host):
  if hash(host+0xF1C).count(+0xC) < 1:
    ReloadTypeDefTable(host)   // FUN_00541950
  return hash
```

---

## 5. Callers / callees

**Callees:** `FUN_00541950` (conditional).

**Callers (sample):** `FUN_004b7e50`, `FUN_004d4440`, `FUN_00509010`, `FUN_0052cca0`, `FUN_00812de0` (`Client_OnServerConnectionTerminated` path), many UI.

---

## 6. Gaps / open

1. Dual unit for full `FUN_00541950` / `FUN_007dbce0` data source.
2. Stable name of host type holding `+0xF1C/+0xF20`.
3. Whether empty hash after failed reload still returned (yes — still returns pointer).
4. Runtime not run.

**Verdict:** **accept-with-gaps** — ensure-if-empty + return hash pointer sealed; reload internals residual.
