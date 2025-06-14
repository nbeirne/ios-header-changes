#ifndef __XPC_SESSION_H__
#define __XPC_SESSION_H__

#ifndef __XPC_INDIRECT__
#error "Please #include <xpc/xpc.h> instead of this file directly."
// For HeaderDoc.
#include <xpc/base.h>
#endif // __XPC_INDIRECT__

#ifndef __BLOCKS__
#error "XPC Session require Blocks support."
#endif // __BLOCKS__

XPC_ASSUME_NONNULL_BEGIN
__BEGIN_DECLS

/*!
 * @define XPC_TYPE_SESSION
 *
 * @discussion
 * Sessions represent a stateful connection between a client and a service. When either end of the connection
 * disconnects, the entire session will be invalidated. In this case the system will make no attempt to
 * reestablish the connection or relaunch the service.
 *
 * Clients can initiate a session with a service that accepts xpc_connection_t connections but session
 * semantics will be maintained.
 *
 */
OS_OBJECT_DECL_SENDABLE_CLASS(xpc_session);

#pragma mark Constants
/*!
 * @typedef xpc_session_create_flags_t
 * Constants representing different options available when creating an XPC
 * Session.
 *
 * @const XPC_SESSION_CREATE_INACTIVE
 * Indicates that the session should not be activated during its creation. The
 * returned session must be manually activated using
 * {@link xpc_session_activate} before it can be used.
 *
 * @const XPC_SESSION_CREATE_MACH_PRIVILEGED
 * Passed to {@link xpc_session_create_mach_service} to indicate that the job
 * advertising the service name in its launchd.plist(5) should be in the
 * privileged Mach bootstrap. This is typically accomplished by placing your
 * launchd.plist(5) in /Library/LaunchDaemons.
 */
XPC_SWIFT_NOEXPORT
XPC_FLAGS_ENUM(xpc_session_create_flags, uint64_t,
	XPC_SESSION_CREATE_NONE XPC_SWIFT_NAME("none") = 0,
	XPC_SESSION_CREATE_INACTIVE XPC_SWIFT_NAME("inactive") = (1 << 0),
	XPC_SESSION_CREATE_MACH_PRIVILEGED XPC_SWIFT_NAME("privileged") = (1 << 1)
);

#pragma mark Handlers
typedef void (^xpc_session_cancel_handler_t)(xpc_rich_error_t error) XPC_SWIFT_NOEXPORT;
typedef void (^xpc_session_incoming_message_handler_t)(xpc_object_t message) XPC_SWIFT_NOEXPORT;
typedef void (^xpc_session_reply_handler_t)(xpc_object_t _Nullable reply,
		xpc_rich_error_t _Nullable error) XPC_SWIFT_NOEXPORT;

#pragma mark Helpers
/*!
 * @function xpc_session_copy_description
 * Copy the string description of the session.
 *
 * @param session
 * The session to be examined.
 *
 * @result
 * The underlying C string description for the provided session. This string
 * should be disposed of with free(3) when done. This will return NULL if a
 * string description could not be generated.
 */
API_AVAILABLE(macos(13.0), ios(16.0), tvos(16.0), watchos(9.0))
XPC_EXPORT XPC_SWIFT_NOEXPORT XPC_WARN_RESULT
char * _Nullable
xpc_session_copy_description(xpc_session_t session);

#pragma mark Client Session Creation
/*!
 * @function xpc_session_create_xpc_service
 * Creates a new session object representing a connection to the named service.
 *
 * @param name
 * The name of the service to create a session with.
 *
 * @param target_queue
 * The GCD queue onto which session events will be submitted. This may be a
 * concurrent queue. This parameter may be NULL, in which case the target queue
 * will be libdispatch's default target queue, defined as
 * DISPATCH_TARGET_QUEUE_DEFAULT.
 *
 * @param flags
 * Additional attributes which which to create the session.
 *
 * @param error_out
 * An out-parameter that, if set and in the event of an error, will point to an
 * {@link xpc_rich_error_t} describing the details of any errors that occurred.
 *
 * @result
 * On success this returns a new session object. The returned session is
 * activated by default and can be used to send messages. The caller is
 * responsible for disposing of the returned object with {@link xpc_release}
 * when it is no longer needed. On failure this will return NULL and if set,
 * error_out will be set to an error describing the failure.
 *
 * @discussion
 * This will fail if the specified XPC service is either not found or is
 * unavailable.
 */
API_AVAILABLE(macos(13.0), macCatalyst(16.0))
API_UNAVAILABLE(ios, tvos, watchos)
XPC_EXPORT XPC_SWIFT_NOEXPORT XPC_RETURNS_RETAINED XPC_WARN_RESULT
xpc_session_t _Nullable
xpc_session_create_xpc_service(const char *name,
		dispatch_queue_t _Nullable target_queue,
		xpc_session_create_flags_t flags,
		xpc_rich_error_t _Nullable * _Nullable error_out);

/*!
 * @function xpc_session_create_mach_service
 * Creates a session with the service defined by the provided Mach service name.
 *
 * @param mach_service
 * The Mach service to create a session with. The service name must exist in the
 * Mach bootstrap that is accessible to the process and be advertised in a
 * launchd.plist.
 *
 * @param target_queue
 * The GCD queue onto which session events will be submitted. This may be a
 * concurrent queue. This parameter may be NULL, in which case the target queue
 * will be libdispatch's default target queue, defined as
 * DISPATCH_TARGET_QUEUE_DEFAULT.
 *
 * @param flags
 * Additional attributes which which to create the session.
 *
 * @param error_out
 * An out-parameter that, if set and in the event of an error, will point to an
 * {@link xpc_rich_error_t} describing the details of any errors that occurred.
 *
 * @result
 * On success this returns a new session object. The returned session is
 * activated by default and can be used to send messages. The caller is
 * responsible for disposing of the returned object with {@link xpc_release}
 * when it is no longer needed. On failure this will return NULL and if set,
 * error_out will be set to an error describing the failure.
 *
 * @discussion
 * This will fail if the specified Mach service is either not found in the
 * bootstrap or is otherwise unavailable.
 *
 */
API_AVAILABLE(macos(13.0), macCatalyst(16.0))
API_UNAVAILABLE(ios, tvos, watchos)
XPC_EXPORT XPC_SWIFT_NOEXPORT XPC_RETURNS_RETAINED XPC_WARN_RESULT
xpc_session_t _Nullable
xpc_session_create_mach_service(const char *mach_service,
		dispatch_queue_t _Nullable target_queue,
		xpc_session_create_flags_t flags,
		xpc_rich_error_t _Nullable * _Nullable error_out);

#pragma mark Session Configuration
/*!
 * @function xpc_session_set_incoming_message_handler
 * Set an incoming message handler for a session.
 *
 * @param session
 * The session to set the handler for.
 *
 * @param handler
 * The handler block to be called when a message originated by the peer is
 * received through the provided session.
 *
 * @discussion
 * This can only be called on an inactive session. Calling this on a session
 * with an existing event handler will replace it.
 */
API_AVAILABLE(macos(13.0), ios(16.0), tvos(16.0), watchos(9.0))
XPC_EXPORT XPC_SWIFT_NOEXPORT
void
xpc_session_set_incoming_message_handler(xpc_session_t session,
		xpc_session_incoming_message_handler_t handler);

/*!
 * @function xpc_session_set_cancel_handler
 * Set the cancel handler for a session.
 *
 * @param session
 * The session to set the cancel handler for.
 *
 * @param cancel_handler
 * The cancel handler block that will be executed when this session is canceled.
 *
 * @discussion
 * This can only be called on an inactive session. Calling this on a session
 * with an existing cancel handler will replace the existing cancel handler with
 * the one provided.
 */
API_AVAILABLE(macos(13.0), ios(16.0), tvos(16.0), watchos(9.0))
XPC_EXPORT XPC_SWIFT_NOEXPORT
void
xpc_session_set_cancel_handler(xpc_session_t session,
		xpc_session_cancel_handler_t cancel_handler);

/*!
 * @function xpc_session_set_target_queue
 * Set the target queue for a session.
 *
 * @param session
 * The session to set the target queue for.
 *
 * @param target_queue
 * The GCD queue onto which session events will be submitted. This may be a
 * concurrent queue. This parameter may be NULL, in which case the target queue
 * will be libdispatch's default target queue, defined as
 * DISPATCH_TARGET_QUEUE_DEFAULT.
 *
 * @discussion
 * This can only be called on an inactive session. Calling this on a session
 * with an existing target queue will replace the existing target queue with
 * the one provided.
 */
API_AVAILABLE(macos(14.0), ios(17.0), tvos(17.0), watchos(10.0))
XPC_EXPORT XPC_SWIFT_NOEXPORT
void
xpc_session_set_target_queue(xpc_session_t session,
		dispatch_queue_t _Nullable target_queue);

#pragma mark Lifecycle
/*!
 * @function xpc_session_activate
 * Activates a session.
 *
 * @param session
 * The session object to activate.
 *
 * @param error_out
 * An out-parameter that, if set and in the event of an error, will point to an
 * {@link xpc_rich_error_t} describing the details of any errors that occurred.
 *
 * @result
 * Returns whether session activation succeeded.
 *
 * @discussion
 * xpc_session_activate must not be called on a session that has been already
 * activated. Releasing the last reference on an inactive session that was
 * created with an xpc_session_create*() will trigger an API misuse crash.
 *
 * If activation fails, the session is automatically cancelled. 
 */
API_AVAILABLE(macos(13.0), ios(16.0), tvos(16.0), watchos(9.0))
XPC_EXPORT XPC_SWIFT_NOEXPORT
bool
xpc_session_activate(xpc_session_t session,
		xpc_rich_error_t _Nullable * _Nullable error_out);

/*!
 * @function xpc_session_cancel
 * Cancels the session. After this call, any messages that have not yet been
 * sent will be discarded, and the connection will be unwound. If there are
 * messages that are awaiting replies, they will have their reply handlers
 * invoked with an appropriate {@link xpc_rich_error_t}.
 *
 * @param session
 * The session object to cancel.
 *
 * @discussion
 * Session must have been activated to be canceled. Cancellation is asynchronous
 * and non-preemptive.
 */
API_AVAILABLE(macos(13.0), ios(16.0), tvos(16.0), watchos(9.0))
XPC_EXPORT XPC_SWIFT_NOEXPORT
void
xpc_session_cancel(xpc_session_t session);

#pragma mark Message Send
/*!
 * @function xpc_session_send_message
 * Sends a message over the session to the destination service.
 *
 * @param session
 * The session to send the message over.
 *
 * @param message
 * The message to send. This must be a dictionary object.
 *
 * @result
 * In the event of an error this will return an {@link xpc_rich_error_t}
 * detailing the reasons for the failure. On success this return value will be
 * NULL.
 *
 * @discussion
 * Messages are delivered in FIFO order. This API is safe to call from multiple
 * GCD queues. There is no indication that a message was delivered successfully.
 * This is because even once the message has been successfully enqueued on the
 * remote end, there are no guarantees about when the runtime will dequeue the
 * message and invoke the other session's event handler block.
 *
 * If this is invoked on an inactive session, one created using the
 * XPC_SESSION_CREATE_INACTIVE flag and hasn't yet been activated, the process
 * will crash.
 */
API_AVAILABLE(macos(13.0), ios(16.0), tvos(16.0), watchos(9.0))
XPC_EXPORT XPC_SWIFT_NOEXPORT XPC_RETURNS_RETAINED XPC_WARN_RESULT
xpc_rich_error_t _Nullable
xpc_session_send_message(xpc_session_t session, xpc_object_t message);

/*!
 * @function xpc_session_send_message_with_reply_sync
 * Sends a message over the session to the destination service and blocks the
 * caller until a reply is received.
 *
 * @param session
 * The session over which the message will be sent.
 *
 * @param message
 * The message to send. This must be a dictionary object.
 *
 * @param error_out
 * If this parameter is provided, in the event of a failure it will point to an
 * {@link xpc_rich_error_t} describing the details of the error.
 *
 * @result
 * On success, this will return the reply message as an {@link xpc_object_t}.
 * Otherwise NULL is returned.
 *
 * @discussion
 * This API supports priority inversion avoidance and should be used instead of
 * combining xpc_session_send_message_with_reply_async with a semaphore.
 *
 * If this is invoked on an inactive session, for example one created using the
 * XPC_SESSION_CREATE_INACTIVE flag that hasn't yet been activated, the process
 * will crash.
 * 
 * Invoking this API while the target queue is blocked would lead to deadlocks
 * in certain scenarios. For that reason, invoking it from the target queue
 * results in a crash.
 *
 * Be judicious about your use of this API. It can block indefinitely, so if you
 * are using it to implement an API that can be called from the main queue, you
 * may wish to consider allowing the API to take a queue and callback block so
 * that results may be delivered asynchronously if possible.
 */
API_AVAILABLE(macos(13.0), ios(16.0), tvos(16.0), watchos(9.0))
XPC_EXPORT XPC_SWIFT_NOEXPORT XPC_RETURNS_RETAINED XPC_WARN_RESULT
xpc_object_t _Nullable
xpc_session_send_message_with_reply_sync(xpc_session_t session,
		xpc_object_t message, xpc_rich_error_t _Nullable * _Nullable error_out);

/*!
 * @function xpc_session_send_message_with_reply_async
 * Sends a message over the session to the destination service and executes the
 * provided callback when a reply is received.
 *
 * @param session
 * The session over which the message will be sent.
 *
 * @param message
 * The message to send. This must be a dictionary object.
 *
 * @param reply_handler
 * The handler block to invoke when a reply to the message is received from the
 * session. If the session is torn down before the reply was received, for
 * example if the remote service exits prematurely, this handler will be
 * executed and passed an appropriate {@link xpc_rich_error_t} object describing
 * the failure.
 *
 * @discussion
 * If this is invoked on an inactive session, for example one created using the
 * XPC_SESSION_CREATE_INACTIVE flag that hasn't yet been activated, the process
 * will crash.
 *
 * If this is invoked on a cancelled session, this will generate a simulated
 * crash.
 */
API_AVAILABLE(macos(13.0), ios(16.0), tvos(16.0), watchos(9.0))
XPC_EXPORT XPC_SWIFT_NOEXPORT
void
xpc_session_send_message_with_reply_async(xpc_session_t session,
		xpc_object_t message, xpc_session_reply_handler_t reply_handler);

/*!
 * @function xpc_session_set_peer_code_signing_requirement
 * Requires that the session peer satisfies a code signing requirement.
 *
 * @param session
 * The session object which is to be modified.
 *
 * @param requirement
 * The code signing requirement to be satisfied by the peer. It is safe to
 * deallocate the requirement string after calling this function.
 *
 * @result
 * 0 on success, non-zero on error
 *
 * @discussion
 * This function will return an error promptly if the code signing requirement
 * string is invalid.
 *
 * It is a programming error to call `xpc_session_set_peer_*requirement` more
 * than once per session.
 *
 * All messages received on this session will be checked to ensure they come
 * from a peer who satisfies the code signing requirement. When message or a
 * reply is received on the session and the peer does not satisfy the
 * requirement the session will be cancelled. A rich error describing the peer
 * code signing error will be passed to the cancellation handler. For
 * `xpc_session_send_message_with_reply_*` NULL will be returned instead of
 * reply, with `error_out` pointing to that rich error.
 *
 * @see https://developer.apple.com/documentation/technotes/tn3127-inside-code-signing-requirements
 */
API_AVAILABLE(macos(14.4))
API_UNAVAILABLE(ios, tvos, watchos)
XPC_EXPORT XPC_NONNULL_ALL XPC_WARN_RESULT
int
xpc_session_set_peer_code_signing_requirement(xpc_session_t session, const char *requirement);

/*!
 * @function xpc_session_set_peer_requirement
 * Requires that the session peer satisfies a requirement.
 *
 * @param session
 * The session object which is to be modified. Must be inactive.
 *
 * @param requirement
 * The requirement to be satisfied by the peer. It will be retained by XPC.
 *
 * @discussion
 * It is a programming error to call `xpc_session_set_peer_*requirement` more
 * than once per session.
 *
 * All messages received on this session will be checked to ensure they come
 * from a peer who satisfies the requirement. When a reply is expected on the
 * session and the peer does not satisfy the requirement, the session will be
 * canceled with cancellation handler called with a rich error describing the
 * peer code signing error. For `xpc_session_send_message_with_reply_sync` NULL
 * will be returned instead of reply, with `error_out` (if set) pointing to the
 * rich error describing the peer code signing error.
 */
API_AVAILABLE(macos(26.0), ios(26.0))
API_UNAVAILABLE(tvos, watchos)
XPC_EXPORT XPC_SWIFT_NOEXPORT XPC_NONNULL_ALL
void
xpc_session_set_peer_requirement(xpc_session_t session, xpc_peer_requirement_t requirement);

/* This is included for compatibility and should not be used in new code */
#define XPC_TYPE_SESSION (&_xpc_type_session)
XPC_EXPORT
XPC_TYPE(_xpc_type_session);

__END_DECLS
XPC_ASSUME_NONNULL_END

#endif // __XPC_SESSION_H__
