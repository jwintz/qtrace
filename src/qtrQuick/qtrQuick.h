/* qtrQuick.h --- 
 * 
 * Author: Julien Wintz
 * Created: Mon Jan 28 21:31:36 2013 (+0100)
 * Version: 
 * Last-Updated: Mon Jan 28 21:48:30 2013 (+0100)
 *           By: Julien Wintz
 *     Update #: 20
 */

/* Change Log:
 * 
 */

#pragma once

class qtrQuick
{
public:
    static qtrQuick *instance(void);

public:
    void initialize(void);

protected:
     qtrQuick(void);
    ~qtrQuick(void);

private:
    static qtrQuick *s_instance;
};
