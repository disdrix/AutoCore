# Annotated low-level: CDlgTrade2d_CreateChildWidgets

| Field | Value |
|---|---|
| Stable ID | `aa_008847f0` |
| VA | `0x008847f0` |
| System | inventory-transfer |
| Date | 2026-07-29 |

---

## Recovery notes

- Ghidra decompiler fails: **Overlapping input varnodes** (`force_decompile` same).
- Full body from `disassemble_function` (1213 insn) + signature + globals audit.
- Vtable DATA `@ 0x00a56ad8` → this VA (sole xref).
- Dual review: `reviews/A|B_aa_008847f0_CDlgTrade2d_CreateChildWidgets.md`.

## Construction pattern (repeated)

```
operator_new(size)
if nonzero → specialized_ctor
host.vtbl[+0xa8](child)          // AddChild
child.vtbl[+0x28](xml_path)      // load skin
optional child.vtbl[+0xfc](1, 0.5f)
host+slot = child
host+0x68++; update +0x74 float; maybe max +0x70
host.vtbl[+0x3f4](1)             // after many groups
```

## Specialized ctors / sizes

| Ctor | Size | Role |
|---|---:|---|
| `FUN_007b5dd0` | `0x488` | Base NDUI window |
| `FUN_00864f20` | `0x4bc` | FX subclass |
| `FUN_0079c860` | `0x4cc` | Button |
| `FUN_008609b0` | `0x578` | Inventory grid widget |
| `FUN_00795f20` | `0x4a4` | Edit box (credit digits) |
| `FUN_0097ffa0` | `0x4f8` | Balance gauge |

## Inventory bind (critical)

| Side | Host slot | Inventory source | Widget id | Notes |
|---|---|---|---:|---|
| You | `+0x588` | `*(DAT_00d1b6d8 + 0xce0)` → grid `+0x56c` | `0x9c42` | `FUN_00860700` refresh |
| Them | `+0x58c` | `*(host+0x510 + 0xce0)` if `host+0x510` | `0x9c43` | `SetOwnerFlag(inv, 6)` |

## Widget IDs

| ID | Hex | Use |
|---:|---|---|
| 40000 | `0x9c40` | Close; also `host+0x49c` |
| 40001 | `0x9c41` | All four local credit edits |
| 40002 | `0x9c42` | inv_you |
| 40003 | `0x9c43` | inv_them |
| 40004 | `0x9c44` | Accept |
| 40005 | `0x9c45` | Cancel |

## Host slot map (stores)

| Off | Content |
|---:|---|
| `+0x49c` | `0x9c40` |
| `+0x504` | close* |
| `+0x50c/+0x50d` | 0,0 |
| `+0x510` | partner root* (**read**, not written) |
| `+0x514` | bg_fill* |
| `+0x518` | fx* |
| `+0x51c` | icon* |
| `+0x520` | bg_texture* |
| `+0x52c` | title* |
| `+0x530..538` | frames 1..3* |
| `+0x53c/540` | credit frames you/them* |
| `+0x544` | offer_you* |
| `+0x548` | last of offer_them / bal_title / balance |
| `+0x550/554` | credits_bg you/them* |
| `+0x558..564` | edt_credits_you 1..4* |
| `+0x568..574` | credits_them 1..4* |
| `+0x578` | accept* |
| `+0x57c` | cancel* |
| `+0x580/584` | ready you/them* |
| `+0x588/58c` | inv grids* |
| `+0x590` | gauge* |

## Open questions

- Decompiler unblock for clean C.
- Who sets `host+0x510`.
- Intent of `+0x548` overwrite chain.
