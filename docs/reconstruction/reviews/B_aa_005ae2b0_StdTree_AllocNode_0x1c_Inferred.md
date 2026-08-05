# Review B (skeptical / adversarial): `aa_005ae2b0` StdTree_AllocNode_0x1c_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ae2b0` |
| **VA** | `0x005ae2b0` |
| **Canonical name** | `StdTree_AllocNode_0x1c_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005ae2b0_StdTree_AllocNode_0x1c_Inferred.md` |
| **System** | util / container (MSVC `_Tree` / map) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is list sentinel (`0xC` circular) | Size 0x1C; no self-link here; color/isnil trailer | **Falsified** |
| 2 | Same as `FUN_005ae270` / 0x24 nodes | Distinct VA; size 0x1C; color@+0x18 not +0x20 | **Falsified** merge |
| 3 | Same as `MapFloatTfid_AllocNode` 0x30 | Different size/offsets | **Falsified** |
| 4 | Void / no return value | Callers assign EAX; bytes leave EAX from `operator_new` | **Falsified** void |
| 5 | Fully constructs map head (self-links + isnil) | Only zeros links + color/isnil defaults; **callers** self-link and set isnil=1 | **Falsified** over-claim of full head ctor |
| 6 | Domain = device effect only | 12 multi-system callers (inventory, skill cooldown map, …) | **Falsified** narrow alias |
| 7 | Initializes value payload | +0x0C..+0x17 never written | **Falsified** full-init |
| 8 | Null-safe on OOM for all stores | Final `mov byte [eax+18/19]` unguarded | **Agree** crash-on-null artifact |
| 9 | Product `_Tree` mangled name required | No string/RTTI on VA | **Agree** structural |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Node size 0x1C | **Confirmed** | Heap corruption / wrong free size |
| Link/color/isnil offsets | **Confirmed** | Broken map walks |
| EAX return | **Confirmed** | Lost head pointer |
| Head requires caller post-init | **Confirmed** | Half-built tree if ported alone |
| Value type identity | **Open** | Mis-typed map elements |
| Runtime | **Open** | No live alloc capture |

---

## 3. Cross-check against raw / live / bytes

```
raw ≡ live decompile_function (2026-07-29);
bytes @ 0x005ae2b0:
  push 0x1C
  call operator_new
  add esp,4
  test eax,eax / jz skip first store
  mov dword [eax], 0
  lea ecx,[eax+4] / test / mov [ecx],0
  lea ecx,[eax+8] / test / mov [ecx],0
  mov byte [eax+0x18], 1
  mov byte [eax+0x19], 0
  ret
```

### Head trap

Porting this as “create ready-to-use empty map” **without** the caller epilogue (isnil=1 + self-link + size=0) yields a non-nil empty-looking node and broken iterators. Pair with host duals (`InventoryGrid_ctor`, cooldown map lazy ctor, `FUN_004e7420`).

### Return trap

Do **not** trust Ghidra `void`. AutoCore ports must treat as `void*`-returning allocator.

---

## 4. Surviving contract for AutoCore

```
node = StdTree_AllocNode_0x1c():
  node = new(0x1C)
  node.left = node.parent = node.right = 0
  node.color(+0x18) = 1
  node.isnil(+0x19) = 0
  return node   // EAX
  // value @ +0x0C..+0x17 UNINIT

Head use (callers):
  head = Alloc(); head.isnil = 1; self-link L/P/R; map.size = 0

AutoCore must NOT:
  - treat as 0xC list sentinel
  - merge with 0x24/0x30 tree node allocators
  - assume value_type constructed
  - assume void return
  - bind name solely to effDeviceEffect
```

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| 0x1C alloc + link zeros + color/isnil | **Agree Confirmed** |
| EAX return | **Agree Confirmed** |
| Head pattern is caller-side | **Agree Confirmed** |
| Multi-system callers | **Agree** |
| accept-with-gaps | **Agree** |
| Value payload type sealed | **Reject** — A correctly leaves Open |

---

## 6. Open questions

1. Per-caller `value_type` (12-byte middle) recovery.
2. Whether insert paths for 0x1C nodes share `FUN_005ae1c0` / differ from 0x24 `FUN_005ae2f0`.
3. Runtime OOM / heap size verification.

**Verdict:** **accept-with-gaps** — agree with A; block void-return, full-head-ctor, and domain-narrowing mistakes.
